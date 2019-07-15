#include <string>
#include <iostream>

#include "longest_Palindrome.h"
#include "increasingTriplet.h"
#include "test_list.h"
#include "leetcoderob.h"
#include "findCycleListIndex.h"

#include "topkFrequent.h"
#include "invertTree.h"
#include "topKbig.h"
#include "maximalsquare.h"

#include "solution_compose.h"
#include "solution_assembly.h"
#include "solution_maxarea.h"
#include "solution_rob.h"
#include "solution_generatebracket.h"
#include "solution_permute.h"
#include "solution_jump.h"
#include "solution_uniqueway.h"
#include "solution_isvalidbfs.h"

#include "solution_stringexist.h"

#include "solution_mergearray.h"

#include "solution_anagrams.h"

#include "solution_maxvalidbracker.h"

#include "solution_change_money.h"
#include "solution_longest_substring.h"
#include "solution_allsubsets.h"
#include "solution_longest_consecutive.h"
#include "solution_rotatematrix.h"
#include "solution_wordbreak.h"
#include "solution_maximalRectangle.h"
#include "solution_stringdecode.h"
#include "solution_stockmaxprofit.h"
#include "solution_divide.h"



static const char *usage = "Please select your question:\n"
    "1、 打家劫舍 \n"
    "2、 递增三元组 \n"
    "3、 存在环的链表的入口 \n"
    "4、 前k的高频元素 \n"
    "5、 第k大的元素 \n"
    "6、 二维数组最大面积 \n"
    "7、 生成括号 \n"
    "8.  是否是二叉搜索树 \n"
    "9.  字符串是否存在于二维数组 \n"
    "10.  合并数组 \n"
    "11. 最长有效括号 \n"
    "12. 整币兑零 \n"
    "13. 最长的无重复字符的子串 \n"
    "14. 给定数组的所有子集 \n"
    "15. 顺时针旋转矩阵90度 \n"
    "16. 单次拆分 \n"
    "17. 矩阵中的最大矩形 \n"
    "18. 字符串解码 \n"
    "19. 股票最大利润 \n"
    "20. 除法运算 \n"
    ;

static int select_num = 0;

void PrintUsage()
{
    cout << usage << endl;
    cin >> select_num;
}

int main(int argc,const char **argv)
{

    PrintUsage();

    cout << "your select num is "<< select_num << endl << endl;

    switch (select_num)
    {
    case 1:
        {
            SolutionRob rob;
            rob.answer();
        }
        break;

    case 2:
        /* code */
        {
            SolutionTriplet solution;
            solution.answer();
        }
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        {
            SolutiontopkFrequent solution;
            solution.answer();
        }        
        break;
    case 5:
        {
            SolutiontopkBig solution;
            solution.answer();
        }
        /* code */
        break;       
    case 6:
        /* code */
        {
            SolutionMaxSquare solution;
            solution.answer();
        }
        break;   
    case 7:
        /* code */
        {
            SolutionGenerateBracket solution;
            solution.answer();
        }
        break;                                    
    case 8:
        /* code */
        {
            SolutionValidBfs solution;
            solution.answer();
        }
        break;  
    case 9:
        /* code */
        {
            SolutionStringExist solution;
            solution.answer();
        }
        break;     

    case 10:
        /* code */
        {
            SolutionMergeArray solution;
            solution.answer();
        }
        break;     
    case 11:
        /* code */
        {
            SolutionMaxValidBracker solution;
            solution.answer();
        }
        break;         
    case 12:
        /* code */
        {
            SolutionChangeMoney solution;
            solution.answer();
        }
        break; 

    case 13:
        /* code */
        {
            SolutionChangeMoney solution;
            solution.answer();
        }
        break; 

    case 14:
        /* code */
        {
            SolutionAllSubsets solution;
            solution.answer();
        }
        break; 
    case 15:
        /* code */
        {
            SolutionRotateMatrix solution;
            solution.answer();
        }
        break; 
    case 16:
        /* code */
        {
            SolutionWordBreak solution;
            solution.answer();
        }
        break; 
    case 17:
        /* code */
        {
            SolutionMaximalRectangle solution;
            solution.answer();
        }
        break; 
    case 18:
        /* code */
        {
            SolutionStringDecode solution;
            solution.answer();
        }
        break; 
    case 19:
        /* code */
        {
            SolutionStockMaxProfit solution;
            solution.answer();
        }
        break; 
    case 20:
        /* code */
        {
            SolutionDivide solution;
            solution.answer();
        }
        break; 
    default:
        PrintUsage();
        break;
    }

     return 0;

}

