#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
    char s[1000];
    char vars[100][10];
    int var_index = 0;
    char current_var[20] = "";
    bool recording_variable = true;
    bool recorded = false;

    for(int r = 0; r < 2; ++r)
    {
        cin.getline(s, 1000);
        if(r == 1)
        {
            recording_variable = true;
            recorded = false;
            memset(current_var, 0, sizeof(current_var));
        }
        for(int i = 0; i < strlen(s); ++i)
        {
            if(r == 0 && s[i] == '*')
            {
                continue;
            }else if(recording_variable && ('A' <= s[i] && s[i] <= 'Z' || 'a' <= s[i] && s[i] <= 'z' || '0' <= s[i] && s[i] <= '9' || s[i] == '_'))
            {
                current_var[strlen(current_var)] = s[i];
                recorded = true;
            }else if(s[i] == '=' || s[i] == ';' || s[i] == '[')
            {
                if(recording_variable)
                {
                    if(r == 0)
                    {
                        strcpy(vars[var_index++], current_var);
                    }else
                    {
                        bool flag = false;
                        for(int j = 0; j < var_index; ++j)
                        {
                            if(strcmp(vars[j], current_var) == 0)
                            {
                                flag = true;
                                break;
                            }
                        }
                        if(!flag)
                        {
                            cout << current_var << ' ';
                        }
                    }

                    memset(current_var, 0, sizeof(current_var));
                    recorded = false;
                }
                if(r == 0)
                {
                    recording_variable = false;
                }
            }else if(s[i] == ' ')
            {
                if(recording_variable && recorded)
                {
                    if(r == 0)
                    {
                        strcpy(vars[var_index++], current_var);
                    }else
                    {
                        bool flag = false;
                        for(int j = 0; j < var_index; ++j)
                        {
                            if(strcmp(vars[j], current_var) == 0)
                            {
                                flag = true;
                                break;
                            }
                        }
                        if(!flag)
                        {
                            cout << current_var << ' ';
                        }
                    }
                    memset(current_var, 0, sizeof(current_var));
                    recorded = false;
                }
            }else if(s[i] == ',' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                if(recording_variable)
                {
                    if(r == 0)
                    {
                        strcpy(vars[var_index++], current_var);
                    }else
                    {
                        bool flag = false;
                        for(int j = 0; j < var_index; ++j)
                        {
                            if(strcmp(vars[j], current_var) == 0)
                            {
                                flag = true;
                                break;
                            }
                        }
                        if(!flag)
                        {
                            cout << current_var << ' ';
                        }
                    }
                    memset(current_var, 0, sizeof(current_var));
                    recorded = false;
                }
                recording_variable = true;
            }
        }
        if(r == 0)
        {
            for(int i = 0; i < var_index; ++i)
            {
                char s_int[] = "int";
                if(strcmp(vars[var_index], s_int) == 0)
                {
                    memset(vars[var_index], 0, sizeof(vars[var_index]));
                }

                cout << vars[i] << endl;
            }
        }
    }
    return 0;
}


