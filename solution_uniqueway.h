
#ifndef __SOLUTION_UNIQUE_WAY_H_
#define __SOLUTION_UNIQUE_WAY_H_

#include <vector>
using namespace std;

//һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ��Start�� ����
//
//������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ��Finish������
//
//���ܹ��ж�������ͬ��·����

class SolutionUniqueWay {
public:
    int uniquePaths(int m, int n) {

        int (*dp)[][n] = (int (*) [][n])new int[m *n];


        delete []dp;

        return 0;

    }

    void answer()
    {
        int  path_all = uniquePaths(5,4);

        cout << path_all << endl;
    }
};

#endif // __SOLUTION_UNIQUE_WAY_H_
