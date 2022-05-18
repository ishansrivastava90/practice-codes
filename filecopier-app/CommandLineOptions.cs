using CommandLine;

namespace FileCopier
{
    public class CommandLineOptions
    {
        [Option(longName: "src", Required=true, HelpText="Absolute path to src directory")]
        public string SourcePath { get; set; }

        
        [Option(longName: "dest", Required=true, HelpText="Absolute path to destination directory")]
        public string DestPath { get; set; }

        [Option(Default=false, Required=false, HelpText="Search recursively in all child directories")]
        public bool Recursive {get; set;}
    }
}