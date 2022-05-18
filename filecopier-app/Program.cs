namespace FileCopier
{
    class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Hello, World!");

            string srcDir = "D:\\Wedding_photos_videos\\Album_Jodhpur";
            string destDirPath = "D:\\Wedding_photos_videos\\Wedding Photos\\Official + Raw";

            // Enumerate the src directory to get all file names
            List<string> srcFileNames = Directory.GetFiles(srcDir, "*", SearchOption.AllDirectories).Select(path => Path.GetFileName(path)).ToList();
            //printFiles("Src", srcFileNames);

            // Enumerate the dest directory and it's sub-directories with CR2 extension
            List<string> filePaths = Directory.GetFiles(destDirPath, "*.CR2", SearchOption.AllDirectories).ToList();
            //printFiles("Raw", filePaths);
            
            foreach (string fullSrcFile in srcFileNames)
            {
                string srcFile = fullSrcFile.Contains(".") ? fullSrcFile.Split(".")[0] : fullSrcFile;
                string srcFileRaw = srcFile + ".CR2";
                List<string> matched = filePaths.Where(path => srcFileRaw.Equals(Path.GetFileName(path))).ToList();
                if (!matched.Any())
                {
                    // Print
                    //Console.WriteLine("File not matched: " + srcFileRaw);
                    Console.WriteLine(srcFileRaw);
                    continue;
                }
                //printFiles("Matched", matched);
                //File.Copy(matched[0], destDirPath + "\\" +srcFileRaw);


            }
       }

       public static void printFiles(string messagePrefix, List<string> files)
       {
           foreach(string file in files)
           {
               if (!String.IsNullOrEmpty(messagePrefix))
               {
                   Console.Write(messagePrefix + ": ");
               }
               Console.WriteLine(file);
           }
       }
    }
}
