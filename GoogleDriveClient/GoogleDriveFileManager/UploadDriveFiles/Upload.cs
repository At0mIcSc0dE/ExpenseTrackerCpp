using System;
using GoogleDriveFileManager;

namespace UploadDriveFiles
{
    class Program
    {
        static void Main(string[] args)
        {
            GoogleDriveFileManager.Upload.UploadExpTrcFile(args[0]);
        }
    }
}
