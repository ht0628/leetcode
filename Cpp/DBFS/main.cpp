#include "bfs.h"
#include "dfs.h"

int main()
{
    DFS* dfs = new DFS();
    BFS* bfs = new BFS();

    vector<string> vec1_1 = {"hot","dot","dog","lot","log","cog"};
    int val1_1 = bfs->ladderLength("hit", "cog", vec1_1);
    cout << val1_1 << endl;
    int val1_2 = bfs->ladderLength2("hit", "cog", vec1_1);
    cout << val1_2 << endl;

    vector<vector<string>> vec1_3 = bfs->findLadders("hit", "cog", vec1_1);
    for(int i = 0; i < vec1_3.size(); i++){
        printContrainer(vec1_3[i]);
    }

    vector<vector<char>> vec1_4 = {{'X','O','X'},{'O','X','O'},{'X','O','X'}};
    for(int i = 0; i < vec1_4.size(); i++){
        printContrainer(vec1_4[i]);
    }
    cout << endl;
    bfs->solve(vec1_4);
    for(int i = 0; i < vec1_4.size(); i++){
        printContrainer(vec1_4[i]);
    }


}