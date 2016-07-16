#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{
    if(argc == 1)
    {
        cout << "Alias name not provided" << endl;
        return 1;
    }
    string s_cwd(getcwd(NULL,0));
    string homedir(getenv("HOME"));
    string alias_name = argv[1];
    std::ofstream outfile;
    outfile.open(homedir + "/.zsh_alias", std::ios_base::app);
    outfile << "alias "+alias_name+"=\"cd "+s_cwd+"\""; 
    string command = "source " + homedir + "/.zshrc";
    system(command.c_str());
    return 0;
}
