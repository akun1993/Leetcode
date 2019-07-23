#ifndef SOLUTION_COMPOSE_H_INCLUDED
#define SOLUTION_COMPOSE_H_INCLUDED

#include <vector>
#include <ISolution.h>
using namespace std;

using namespace std;
class SolutionPermute : public ISolution
{
    public:
        vector<vector<int> >  permute(int n,int m)
        {
            vector<vector<int> >  mute;

            vector<int> arr;
            for (int i = 0; i < m; i++)
            {
                arr.push_back(1);
            }
            int i = 0;

            int count = 0;

            while (true)
            {
               // arr[i] = ;
                bool flag = true;

                for(int j = 0; j < i ; ++j)
                {
                    if(arr[i] == arr[j])
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag && i == m - 1)
                {
                    //���һ�����
                    for (int j = 0; j < m; j++)
                    {
                        cout << arr[j];
                    }
                    cout << endl;
                    ++count;
                }

               if (flag && i < m - 1)
               {
                   ++i;

                   arr[i] = 1;

                   continue;
                }

                while (arr[i] == n)
                {
                    --i;
                }


                if (i >= 0)
                    ++arr[i];
                else
                    break;

            }
            cout << "total number  " << count <<endl;

            return mute;
        }

        void answer()
        {
            permute(5,4);
        }
};

#endif // SOLUTION_COMPOSE_H_INCLUDED
