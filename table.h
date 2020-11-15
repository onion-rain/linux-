#ifndef TABLE_H
#define TABLE_H

#include "struct.h"
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<time.h>
#include<iostream>
#include "BPlusTree.h"

#define RECORD_FILE "record" //表存储文件名


class table
{

    public:
        static table *GetTable(int init);               //获取table对象指针
        void InsertRecord();                            //添加记录
        void SearchRecord(int left, int right, int col);//查询第col列属性值位于区间(left,right)的所有记录
        void DisplayAllRecord();                        //展示全部记录

    private:
        table(int init);
        ~table();
        Record CreateRecord();                          //创建一条随机记录
        bool AppendRecord(const Record &record);        //保存一条记录
        BPlusTreeNode* CreateBPlusTree(int col);        //为第col列的属性创建B+树
        void UpdateIndexFile(int col);                  //更新索引文件
        void CreateIndexFile(BPlusTreeNode* root, int col);
        void DisplayRecord(const Record &record);       //显示记录
        bool Is_Index_File_Exists(int col);             //判断索引文件是否存在
        void InitializeTable(int num);                         //初始化表格
        static pthread_mutex_t *InitializeMutex();      //初始化互斥量

    private:
        int m_Fd;                                       //文件描述符
        int64_t record_num;                             //表中已有记录数量
        Record* records;                                //表

        BPlusTree* tree;                                //B+树
        pthread_mutex_t *m_pMutexForOperatingTable;     //互斥访问表

        static pthread_mutex_t *m_pMutexForCreatingTable;//用于table实例的创建，保证只创建一个table实例

        static table *m_table;
};


#endif // TABLE_H
