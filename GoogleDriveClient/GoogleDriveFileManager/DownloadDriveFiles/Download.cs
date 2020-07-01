using System;
using GoogleDriveFileManager;

namespace DownloadDriveFiles
{
    class Program
    {
        static void Main(string[] args)
        {
            GoogleDriveFileManager.Download.DownloadExpTrcFile(args[0]);
        }
    }
}
