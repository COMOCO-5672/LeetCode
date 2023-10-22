#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>

int n;

std::string plusOne(std::string code, int j)
{
    if (code[j] == '9') {
        code[j] = '0';
    } else {
        code[j] += 1;
    }

    return code;
}

std::string minusOne(std::string code, int j)
{
    if(code[j] == '0') {
        code[j] = '9';
    } else {
        code[j] -= 1;
    }
    return code;
}

int BFS(std::vector<std::string>& deadends, std::string target)
{
        std::queue<std::string> q;
        std::unordered_set<std::string> version;
        std::unordered_set<std::string> dead;
 
        for (std::string str : deadends)  dead.insert(str);
 
        //把初始密码添加到队列中
        q.push("0000");
        version.insert("0000");
 
        int depth = 0;
 
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                std::string cur = q.front();
 
                q.pop();            //使用队列中第一个元素后，立刻把其删除，不要放在后面删除，以防出现 bug
 
                //判断是否是正确密码
                if (dead.find(cur) != dead.end()) continue;
                if (cur == target) return depth;
                //if (!cur.compare(target)) return depth;
 
                for (int j = 0; j < 4; j++)
                {
                    //转动一次密码并添加到队列中
                    std::string up = plusOne(cur, j);
 
                    //判断是否是回头路
                    if (version.find(up) == version.end())
                    {
                        q.push(up);
                        version.insert(up);
                    }
                    
                    std::string down = minusOne(cur, j);
                    if (version.find(down) == version.end())
                    {
                        q.push(down);
                        version.insert(down);
                    }
                }
 
                
            }
            depth++;
        }
        return -1;
}

int main()
{
    std::string a = "1112";
    std::vector<std::string> deadcodes = {"1111", "2222"};
    std::cout << BFS(deadcodes, a);
    return 0;
}