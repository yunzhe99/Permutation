/***********************************************/
/*      File: n_array.cpp                         */
/*      Author: Li  Yunzhe                     */
/*      Contact: liyunzhe@whu.edu.cn           */
/*      License: Copyright (c) 2019 Li Yunzhe  */
/***********************************************/

/*已经实现在较快速的情况下，将不重复的排列输出
  但是，由于某种原因，最后会多一些没有意义的零*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include<ctime>
#define nn 12//笔画数
using namespace std;

int num = 0;


void get_result_in_vector(vector<vector<int> > & vec,int N,vector<int> &tmp, vector<vector<int>>& tmp_result)
{
    for(int i = 0;i<vec[N].size();++i)
    {
        if(find(tmp.begin(),tmp.end(),vec[N][i])!=tmp.end())
        {
            ;
        }
        else{
        tmp.push_back(vec[N][i]);
        if (N<vec.size()-1)
        {
            get_result_in_vector(vec,N+1,tmp, tmp_result);
        }
        else
        {
            vector<int> one_result;
            for (int i = 0;i<tmp.size();++i)
            {
                one_result.push_back(tmp.at(i));
            }
            tmp_result.push_back(one_result);
        }
        tmp.pop_back();
        }
    }
}

void get_all_combination(vector<vector<int>>& vec, int result[][nn])
{
    vector<int> tmp_vec;

    vector<vector<int>> tmp_result;
    get_result_in_vector(vec,0,tmp_vec, tmp_result);

    //将vector中的数据转化为数组保存
    for (int i = 0; i < tmp_result.size(); i++){
        for (int j = 0; j < tmp_result.at(i).size(); j++)
        {
            result[i][j] = tmp_result.at(i).at(j);
            num++;
        }
    }
}

int main()
{

    int arr1[] = {2,4};
    int arr2[] = {3,5,6,7,8,9,11};
    int arr3[] = {1,10};
    int arr4[] = {1,10};
    int arr5[] = {3,7,8,9};
    int arr6[] = {2,4};
    int arr7[] = {12};
    int arr8[] = {3,5,6,7,8,9,11};
    int arr9[] = {3,5,6,7,8,9,11};
    int arr10[] = {3,5,6,7,8,9,11};
    int arr11[] = {3,5,6,7,8,9,11};
    int arr12[] = {3,5,6,7,8,9,11};
    const int first_dimension = sizeof(arr1)/sizeof(arr1[0]) * sizeof(arr2)/sizeof(arr2[0]) * sizeof(arr3)/sizeof(arr3[0]) * sizeof(arr4)/sizeof(arr4[0]) * sizeof(arr5)/sizeof(arr5[0]) * sizeof(arr6)/sizeof(arr6[0]) * sizeof(arr7)/sizeof(arr7[0]) * sizeof(arr8)/sizeof(arr8[0]) * sizeof(arr9)/sizeof(arr9[0]);// * sizeof(arr10)/sizeof(arr10[0]) * sizeof(arr11)/sizeof(arr11[0]) * sizeof(arr12)/sizeof(arr12[0]);
    //所有组合的结果
    int result[first_dimension][nn];

    clock_t start,end;

    start = clock();

    vector<vector<int>> vec;
    vec.push_back(vector<int>(arr1,arr1+sizeof(arr1)/sizeof(arr1[0])));
    vec.push_back(vector<int>(arr2,arr2+sizeof(arr2)/sizeof(arr2[0])));
    vec.push_back(vector<int>(arr3,arr3+sizeof(arr3)/sizeof(arr3[0])));
    vec.push_back(vector<int>(arr4,arr4+sizeof(arr4)/sizeof(arr4[0])));
    vec.push_back(vector<int>(arr5,arr5+sizeof(arr5)/sizeof(arr5[0])));
    vec.push_back(vector<int>(arr6,arr6+sizeof(arr6)/sizeof(arr6[0])));
    vec.push_back(vector<int>(arr7,arr7+sizeof(arr7)/sizeof(arr7[0])));
    vec.push_back(vector<int>(arr8,arr8+sizeof(arr8)/sizeof(arr8[0])));
    vec.push_back(vector<int>(arr9,arr9+sizeof(arr9)/sizeof(arr9[0])));
    vec.push_back(vector<int>(arr10,arr10+sizeof(arr10)/sizeof(arr10[0])));
    vec.push_back(vector<int>(arr11,arr11+sizeof(arr11)/sizeof(arr11[0])));
    vec.push_back(vector<int>(arr12,arr12+sizeof(arr12)/sizeof(arr12[0])));
    get_all_combination(vec, result);

    FILE * fp;
    if((fp = fopen("text_2.txt","wb"))==NULL){
      printf("cant open the file");
      exit(0);
    }

    //输出结果
    for (int i = 0; i < num/11; i++)
    {
        for (int j = 0; j < nn; j++)
        {
            cout<<result[i][j]<<"\t";
            fprintf(fp,"%d ",result[i][j]);
        }
        cout<<endl;
        fprintf(fp,"\n ");
    }
    fclose(fp);

    end=clock();

    double endtime=(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"Total time:"<<endtime<<endl;		//s为单位
	cout<<"Total time:"<<endtime*1000<<"ms"<<endl;	//ms为单位




    return 0;
}
