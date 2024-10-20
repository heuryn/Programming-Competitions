#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int ROWS = 6;
const int COLS = 7;

struct FourInARow {
    char player;
    int earliestCompletion;
    int latestCompletion;
};

void findFourInARows(char grid[ROWS][COLS], vector<FourInARow>& connieWins, vector<FourInARow>& forrestWins) {
    int dr[] = {0, 1, 1, 1};
    int dc[] = {1, 0, 1, -1};

    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            char player = grid[r][c];
            if (player != 'C' && player != 'F') continue;
            for (int d = 0; d < 4; ++d) {
                vector<pair<int, int>> cells = { {r, c} };
                bool win = true;
                for (int k = 1; k < 4; ++k) {
                    int nr = r + dr[d] * k;
                    int nc = c + dc[d] * k;
                    if (nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS || grid[nr][nc] != player) {
                        win = false;
                        break;
                    }
                    cells.push_back({ nr, nc });
                }
                if (win) {
                    int Emax = 0, Lmin = 50;
                    for (auto& cell : cells) {
                        int cellE = cell.first + 1;
                        int cellL = cell.first + 37;
                        Emax = max(Emax, cellE);
                        Lmin = min(Lmin, cellL);
                    }
                    vector<int> possibleMoves;
                    for (int move = Emax; move <= Lmin; ++move) {
                        if (player == 'C' && move % 2 == 1) {
                            possibleMoves.push_back(move);
                        } else if (player == 'F' && move % 2 == 0) {
                            possibleMoves.push_back(move);
                        }
                    }
                    if (!possibleMoves.empty()) {
                        FourInARow winInfo = { player, possibleMoves.front(), possibleMoves.back() };
                        if (player == 'C') connieWins.push_back(winInfo);
                        else forrestWins.push_back(winInfo);
                    }
                }
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    string blank;
    getline(cin, blank);
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        char grid[ROWS][COLS];
        getline(cin, blank);
        for (int r = ROWS - 1; r >= 0; --r) {
            string line;
            getline(cin, line);
            for (int c = 0; c < COLS; ++c) {
                grid[r][c] = line[c];
            }
        }
        vector<FourInARow> connieWins, forrestWins;
        findFourInARows(grid, connieWins, forrestWins);

        int minConnieN = 50, minForrestN = 50;
        for (auto& win : connieWins) {
            minConnieN = min(minConnieN, win.earliestCompletion);
        }
        for (auto& win : forrestWins) {
            minForrestN = min(minForrestN, win.earliestCompletion);
        }

        cout << "Case #" << caseNum << ": ";
        if (connieWins.empty() && forrestWins.empty()) {
            cout << "0" << endl;
        } else if (connieWins.empty()) {
            cout << "F" << endl;
        } else if (forrestWins.empty()) {
            cout << "C" << endl;
        } else {
            if (minConnieN < minForrestN) {
                cout << "C" << endl;
            } else if (minForrestN < minConnieN) {
                cout << "F" << endl;
            } else {
                cout << "?" << endl;
            }
        }
    }
    return 0;
}
