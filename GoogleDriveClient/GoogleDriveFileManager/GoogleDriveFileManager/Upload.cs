using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

using Google;
using Google.Apis.Auth.OAuth2;
using Google.Apis.Download;
using Google.Apis.Drive.v3;
using Google.Apis.Drive.v3.Data;
using Google.Apis.Logging;
using Google.Apis.Services;
using Google.Apis.Upload;
using Google.Apis.Util.Store;


namespace GoogleDriveFileManager
{

    public class Upload
    {
        static string[] Scopes = { DriveService.Scope.Drive };

        private async Task Run(String path)
        {
            Console.WriteLine("[DriveUploader:Task] Entered");
            UserCredential credential;
            using (var stream = new FileStream("credentials.json", FileMode.Open, FileAccess.Read))
            {
                credential = await GoogleWebAuthorizationBroker.AuthorizeAsync(
                    GoogleClientSecrets.Load(stream).Secrets,
                    Scopes,
                    "user",
                    CancellationToken.None,
                    new FileDataStore("DriveUploader.ListMyLibrary"),
                    new PromptCodeReceiver()
                );

            }

            DriveService service = new DriveService(new BaseClientService.Initializer()
            {
                HttpClientInitializer = credential,
                ApplicationName = "GoogleDriveFileManager",
            });

            var fileMetadata = new Google.Apis.Drive.v3.Data.File()
            {
                Name = "Data",
                MimeType = "application/json"
        };

            FilesResource.UpdateMediaUpload request;

            //using (var stream = new System.IO.FileStream($"/images/{filename}.{extension}", System.IO.FileMode.Open))
            //using (var stream = new System.IO.FileStream("D:/dev/ProgramFiles/ExpTrc/Data.json", System.IO.FileMode.Open))
            //{
            //    request = service.Files.Update(fileMetadata, "1OyAttZeV8M7gqxTs7FbxfQxvls3wCuYa", stream, mimeType);
            //    request.Fields = "id";
            //    request.Upload();
            //}

            //MINE
            byte[] byteArray = System.IO.File.ReadAllBytes(path);
            using (var stream = new System.IO.MemoryStream(byteArray))
            {
                request = service.Files.Update(fileMetadata, "1OyAttZeV8M7gqxTs7FbxfQxvls3wCuYa", stream, "application/json");
                request.Fields = "id";
                request.Upload();
            }

            var responseFile = request.ResponseBody;
            if (responseFile == null)
            {
                Console.WriteLine($"[DriveUploader:Task] Error: File {path} could not be uploaded.");
            }
            else
            {
                Console.WriteLine($"[DriveUploader:Task] File ID: {responseFile.Id.ToString()}");
            }
            Console.WriteLine("[DriveUploader:Task] Exited");
        }

        public static void UploadExpTrcFile(String path)
        {
            Console.WriteLine("[DriveUploader:Main] Entered");
            try
            {
                new Upload().Run(path).Wait();
            }
            catch (AggregateException ex)
            {
                foreach (var e in ex.InnerExceptions)
                {
                    Console.WriteLine(e.Message);
                }
            }
            Console.WriteLine("[DriveUploader:Main] Exited");
        }
    }
}
