#include "eval/btree.hpp"
#include "input/lexer.hpp"
#include "input/syntax.hpp"
#include "eval/shunting.hpp"
#include "input/iostream.hpp"

int main(int argc, char *argv[])
{
    int _e = 0;
    char *line;
    IOStream ios;
    Shunting sy;
    stack<SToken> tmp;
    BTree *root = NULL;
    Lexer le = Lexer();
    regex rw("(\\t)+|(\\s)+");
    SyntaxAnalyzer sa = SyntaxAnalyzer();

    cout << "Computor-v2 1.0\n  Free Software(c) November 2017, [rap]dean\n   mathware, dean-techonlogies inc.\n" << endl;
    while (1)
    {
        try{
            cout << "\033[1;32m$> \033[0m";
            line = ios.read_line();
            if (!strcmp(line, "quit") || !strcmp(line, "exit") ||
                !strcmp(line, "\\q"))
                exit(EXIT_SUCCESS);
            if (strcmp(line, "") && !regex_match(line, rw))
            {
                le.tokenize(line);
                tmp = sy.shuntingYard(le.getTokens(), _e);
                if (_e)
                {
                    _e = 0;
                    le.delete_map();
                    continue;
                }
                if (!tmp.empty())
                {
                    le.delete_map();                    
                    sa.build_ast(tmp, root);
                    sa.parse(root);
                    // root->print();
                    sa.delete_tree(root);
                }
            }
        }
        catch(IndexOutOfBounds &e){
            cerr << e.what() << endl;
            exit(EXIT_FAILURE);
        }
        catch(InvalidOperatorException &e){
            cerr << "\033[1;31merror:\033[0m " << e.what() << endl;
            exit(EXIT_FAILURE);
        }
        catch(InvalidOperandException &e){
            cerr << "\033[1;31merror:\033[0m " << e.what() << endl;
            exit(EXIT_FAILURE);
        }
        catch(InvalidSyntaxException &e){
            cerr << "\033[1;31merror:\033[0m " << e.what() << endl;
            exit(EXIT_FAILURE);
        }
        catch(invalid_argument &e){
            cerr << "\033[1;31merror:\033[0m invalid_argument: " << e.what() << endl;
        }
    }
    return (0);
}