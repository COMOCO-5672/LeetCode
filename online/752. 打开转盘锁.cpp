#include <iostream>
#include <string>
#include <queue>
#include <set>

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

int BFS(std::string start, std::string target, std::string deadcodes[])
{
    std::queue<std::string> q;
    std::set<std::string> visited;

    q.push(start);
    for (int i = 0; i < n; ++i) {
        visited.insert(deadcodes[i]);
    }

    int step = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            std::string cur = q.front();
            q.pop();

            if(cur == target)
                return step;

            for (int i = 0; i < 4; ++i) {
                std::string up = plusOne(cur, i);

                if (!visited.count(up) && !visited.count(up)) {
                    q.push(up);
                    visited.insert(up);
                }

                std::string down = minusOne(cur, i);

                if (!visited.count(down) && !visited.count(down)) {
                    q.push(down);
                    visited.insert(down);
                }
            }
        }
        ++step;
        std::cout << "step:" << step << std::endl;
    }
    return -1;
}

int main()
{
    std::string start = "0000";
    std::string target = "1239";
    std::string deadcodes[2] = {"1111", "2222"};
    std::cout << BFS(start, target, deadcodes);
    return 0;
}