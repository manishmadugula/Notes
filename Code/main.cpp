#include <bits/stdc++.h>
using namespace std;

//graph

bool permutation(string input1, string input2)
{
    if (input1.length() == input2.length())
    {
        int n = input1.length();
        std::unordered_map<char, int> umap1;
        std::unordered_map<char, int> umap2;
        for (int i = 0; i < n; i++)
        {
            if (umap1.find(input1[i]) != umap1.end())
                umap1[input1[i]] = umap1[input1[i]] + 1;
            else
                umap1.insert(make_pair(input1[i], 1));

            if (umap2.find(input2[i]) != umap2.end())
                umap2[input2[i]] = umap2[input2[i]] + 1;
            else
                umap2.insert(make_pair(input2[i], 1));
        }

        unordered_map<char, int>::iterator it;
        for (it = umap1.begin(); it != umap1.end(); it++)
        {
            if (umap2.find(it->first) != umap2.end())
            {
                if (umap2[it->first] != it->second)
                {
                    return false;
                }
            }
            else
                return false;
        }

        for (it = umap2.begin(); it != umap2.end(); it++)
        {
            if (umap1.find(it->first) != umap1.end())
            {
                if (umap1[it->first] != it->second)
                {
                    return false;
                }
            }
            else
                return false;
        }
    }
    else
    {
        return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    cout << permutation("DEER", "REED");
}

//dfs
// vector<bool> visited;
// vector<vector<int>> graph;

// void edge(int a, int b)
// {
//     graph[a].push_back(b);
//     graph[b].push_back(a);
// }

// void dfs(int node)
// {
//     stack<int> s;
//     s.push(node);
//     visited[node] = true;

//     while (!s.empty())
//     {
//         int n = s.top();
//         s.pop();
//         cout << n << endl;

//         for (auto it = graph[n].begin(); it != graph[n].end(); it++)
//         {
//             if (!visited[(*it)])
//             {
//                 s.push((*it));
//                 visited[(*it)] = true;
//             }
//         }
//     }
// }

// int main()
// {
//     visited.assign(5, false);
//     graph.assign(5, vector<int>());

//     edge(0, 1);
//     edge(0, 4);
//     edge(1, 2);
//     edge(1, 3);
//     edge(1, 4);
//     edge(2, 3);
//     edge(3, 4);
//     dfs(0);
// }

//bfs
// vector<vector<int>> graph; //*
// vector<bool> visited;   //*

// void bfs(int node)
// {
//     queue<int> q;
//     q.push(node);  //*
//     visited[node] = true; //*

//     while (!q.empty())
//     {
//         int n = q.front();   //*
//         cout << n << endl;
//         q.pop();     //*
//         for (size_t i = 0; i < graph[n].size(); i++)
//             if (!visited[graph[n][i]])
//             {
//                 q.push(graph[n][i]);
//                 visited[graph[n][i]] = 1;  //*
//             }
//     }
// }

// int main(int argc, char const *argv[])
// {
//     int n, e;
//     cin >> n >> e;
//     visited.assign(n, false);             //*
//     graph.assign(n, vector<int>());        //*
//     int a, b;
//     for (size_t i = 0; i < e; i++)
//     {
//         cin >> a >> b;
//         graph[a].push_back(b);
//     }
//     bfs(0);
//     return 0;
// }

// //bitset
// int main(int argc, char const *argv[])
// {
//     bitset<10> b(24);
//     cout << b << endl;
//     cout << b[1] << endl;
//     cout << int(b.to_ulong()) << endl;
//     return 0;
// }

// //limits
// int main(int argc, char const *argv[])
// {
//     cout << numeric_limits<int>::min() << endl;
//     cout << numeric_limits<float>::max() << endl;
//     return 0;
// }

//numeric
// struct Custom
// {
//   public:
//     int operator()(int x, int y)
//     {
//         return x * y;
//     }
// } Custom;

// struct Custom2
// {
//   public:
//     int operator()(int x, int y)
//     {
//         return x - y;
//     }
// } Custom2;

// int main(int argc, char const *argv[])
// {
//     //accumulator
//     int a[] = {1, 3, 4, 12, 41, 4, 3};
//     cout << accumulate(a, a + sizeof(a) / sizeof(a[1]), 1, Custom) << endl;

//     //adjacent difference (custom operation)
//     int result[7];
//     adjacent_difference(a, a + 7, result, Custom);
//     for (size_t i = 0; i < 7; i++)
//     {
//         cout << result[i] << endl;
//     }

//     //inner_product
//     int b[] = {2, 4, 14, 1, 4, 2, 4};
//     cout << inner_product(a, a + 7, b, 0, Custom2, Custom) << endl;

//     return 0;
// }

// //complex
// int main(int argc, char const *argv[])
// {
//     complex<int> c(1, 3);
//     cout << c.real() << "+ j" << c.imag() << endl;
//     cout << abs(c) << endl;
//     cout << arg(c) << endl;
//     cout << norm(c) << endl;
//     cout << conj(c) << endl;
//     return 0;
// }

//map
// int main(int argc, char const *argv[])
// {
//     map<int, string> mp;
//     mp.insert(make_pair(3, "Manish"));
//     mp.insert(make_pair(3, "Sunil"));
//     mp.insert(make_pair(4, "Sarmista"));
//     mp.insert(make_pair(6, "U"));
//     mp.insert(make_pair(3, "Me"));
//     if (mp.find(3) != mp.end())
//     {
//         cout << "Found at" << distance(mp.begin(), mp.find(3)) << endl;
//     }
//     cout << mp.lower_bound(3)->second << endl;
//     cout << mp.upper_bound(3)->second << endl;
//     cout << mp.lower_bound(5)->second << endl;
//     cout << mp.upper_bound(5)->second << endl;

//     return 0;
// }

// //unordered_map
// int main(int argc, char const *argv[])
// {
//     unordered_map<string, string> umap;
//     umap.insert(make_pair("Name", "Manish"));
//     umap.insert(make_pair("vlas", "Manifadfsh"));
//     umap.insert(make_pair("Namfde", "Manidfdsh"));
//     unordered_map<string, string>::iterator it = umap.find("Name");

//     if (it != umap.end())
//         cout << it->second << endl;
//     return 0;
// }

// //unordered_set

// int main(int argc, char const *argv[])
// {
//     unordered_multiset<string> set;
//     set.insert("hello");
//     set.insert("how are you");
//     set.insert("hello");

//     unordered_set<string>::iterator it;
//     for (it = set.begin(); it != set.end(); it++)
//     {
//         cout << (*it) << endl;
//     }

//     return 0;
// }

// //Unordered_map

// int main(int argc, char const *argv[])
// {
//     unordered_map<string, int> umap;
//     umap["Manish"] = 10;
//     umap["Pi"] = 13;

//     if (umap.find("sara") == umap.end())
//     {
//         cout << "not found" << endl;
//     }

//     //Iterating map
//     unordered_map<string, int>::iterator it;
//     for (it = umap.begin(); it != umap.end(); it++)
//     {
//         cout << it->first << " " << it->second << endl;
//     }

//     return 0;
// }

// //heap for user-defined class

// class Point
// {
//   public:
//     int x;
//     int y;
//     Point(int x1, int y1)
//     {
//         x = x1;
//         y = y1;
//     }
// };

// class Comparator
// {
//   public:
//     int operator()(Point a, Point b)
//     {
//         return a.x > b.x;
//     }
// };

// main(int argc, char const *argv[])
// {
//     priority_queue<Point, vector<Point>, Comparator> pq;
//     pq.push(Point(1, 2));
//     pq.push(Point(5, 2));
//     pq.push(Point(124, 2));
//     pq.push(Point(4, 2));
//     pq.push(Point(-54, 2));
//     int n = pq.size();

//     for (int i = 0; i < n; i++)
//     {
//         cout << (pq.top()).x << " ";
//         pq.pop();
//     }
//     return 0;
// }

// //Conversions
// int main(int argc, char const *argv[])
// {
//     string s = "3254325";
//     int d = stoi(s);
//     d = d + 1;

//     cout << to_string(d) << endl;
//     return 0;
// }

// //More string operations

// int main(int argc, char const *argv[])
// {
//     //Find all
//     string s = "hello how are  h h h h h h you?";
//     int n = 0;
//     while ((n = s.find("h", n)) != -1)
//     {
//         cout << n << " ";
//         n = n + 1;
//     }
//     cout << endl;

//     //Insert into a string at a specific place.
//     s.insert(6, "Manish ");
//     cout << s << endl;
//     return 0;
// }

// //String operations.
// int main(int argc, char const *argv[])
// {
//     string s = "HI my name is Manish";
//     cout << "Length of the string is" << s.length() << endl;
//     cout << "Null terminated char array version of string" << s.c_str() << endl;
//     s.append(". I am a good boy");
//     cout << "appended string :" << s << endl;
//     string b = ". I want the full stop but not this statement.";
//     // s.append(b, 0, 2);
//     // string c;
//     // cout << "appended string :" << s << endl;
//     //substring
//     s.append(b.substr(0, 3));
//     //erase part of string.
//     s.erase(s.length() - 3, 3);
//     //replace part of string with another string.
//     s.replace(1, 1, b.c_str());
//     return 0;
// }

//Create a string using part of another string.
// int main(int argc, char const *argv[])
// {
//     string s = "HI Manish";
//     string d(s, 3, 6);
//     cout << d << endl;
//     return 0;
// }

// //String to char array
// int main(int argc, char const *argv[])
// {
//     string s = "My name is Manish";
//     char c[s.length()];
//     strcpy(c, s.c_str());
//     char d[] = "My name is Manish";
//     return 0;
// }

// //Char array to string
// int main(int argc, char const *argv[])
// {
//     char a[5] = {'a', 'b', 'c', 'd', 'e'};
//     char b[] = "mansihismytname";
//     cout << b << endl;
//     string s(a);
//     string s2 = b;
//     cout << s << endl;
//     return 0;
// }

// //Generate Random Float
// int main(int argc, char const *argv[])
// {
//     float random = (float)(rand()) / (float)RAND_MAX;
//     cout << random << endl;
//     return 0;

// }

// //Generate Random Integer
// int main(int argc, char const *argv[])
// {

//     long random = rand();
//     cout << random % 100 + 123 << endl;
//     return 0;
// }

//int to binary
// int main(int argc, char const *argv[])
// {
//     cout << std::bitset<32>(-12345).to_string() << endl;
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     char a = '0';
//     int d = a;
//     cout << char(a + 3) << endl;
//     return 0;
// }

// // Convert int to string
// int main(int argc, char const *argv[])
// {
//     int n = 123;
//     string s = to_string(n);
//     cout << s << "2";
//     return 0;
// }

// //Convert string to int
// int main(int argc, char const *argv[])
// {
//     int d;
//     string s = "123";
//     stringstream stream(s);
//     stream >> d;
//     cout << d;

//     return 0;
// }

//Convert hex to dec (same for oct)
// int main(int argc, char const *argv[])
// {
//     int x = 0x70;
//     int d;
//     stringstream s;
//     s << std::dec << x << '\n';
//     // string st(s.str());
//     s >> d;
//     cout << d << endl;
//     return 0;
// }

// //Lower Bound
// int main(int argc, char const *argv[])
// {
//     int a[5] = {4, 6, 8, 9, 13};
//     //Returns an iterator pointing to the first element in the range[first,last) which is not less than the val;
//     cout << *() return 0;
// }

// //Binary Search
// int main(int argc, char const *argv[])
// {
//     float a[5] = {3.0, 13.3, 14.8, 19.2, 20};
//     cout << binary_search(a, a + 5, 3.0);
//     return 0;
// }

// //Check if sorted
// int main(int argc, char const *argv[])
// {
//     int a[5] = {1, 2, 3, 4, 5};
//     int b[5] = {1, 2, 3, 5, 2};
//     cout << is_sorted(a, a + 5) << endl;
//     cout << is_sorted(b, b + 5) << endl;
//     return 0;
// }

// //Nth Element
// int main(int argc, char const *argv[])
// {
//     int a[5] = {3, 2, -1, 42, 0};

//     nth_element(a, a + 2, a + 5);

//     for (size_t i = 0; i < 5; i++)
//         cout << a[i] << endl;

//     return 0;
// }

// //Reversing an array
// int main(int argc, char const *argv[])
// {
//     char a[4] = {'a', 'b', 'd', 'f'};

//     for (size_t i = 0; i < 4; i++)
//         cout << a[i] << " ";

//     cout << endl;
//     reverse(a, a + 2);

//     for (size_t i = 0; i < 4; i++)
//         cout << a[i] << " ";

//     cout << endl;
//     reverse(a, a + 4);

//     for (size_t i = 0; i < 4; i++)
//         cout << a[i] << " ";

//     return 0;
// }

// std::sort is unstable_sort, use std::stable_sort to achieve stable sort.

// //Descending Sorting

// bool compare(int a, int b)
// {
//     return b < a;
// }

// int main(int argc, char const *argv[])
// {
//     vector<int> v = {3, 2, 5, 0, -8};
//     sort(v.begin(), v.end(), compare);
//     for (size_t i = 0; i < v.size(); i++)
//     {
//         cout << v[i] << endl;
//     }

//     return 0;
// }

//Sorting
// int main(int argc, char const *argv[])
// {
//     int a[5] = {1,2,3,-33,2};
//     sort(a,a+5);
//     for(size_t i = 0; i < 5; i++)
//     {
//         cout << a[i] <<endl;
//     }

//     return 0;
// }
