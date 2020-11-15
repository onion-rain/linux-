#include <iostream>
#include<string>
#include<stdlib.h>
#include "table.h"
#include "CLThread.h"
#include "CLExecutiveFunctions.h"

// //多线程空表插入
// int main()
// {
//     table* m_table=table::GetTable(false);

//     m_table->DisplayAllRecord();

//     CLExecutiveFunctions* Insert1=new CLExecutiveFunctionInsert(m_table);
//     CLExecutiveFunctions* Insert2=new CLExecutiveFunctionInsert(m_table);
//     CLThread *pThread1=new CLThread(Insert1);
//     CLThread *pThread2=new CLThread(Insert2);
//     pThread1->Run();
//     pThread2->Run();
//     pThread1->WaitForDeath();
//     pThread2->WaitForDeath();

//     m_table->DisplayAllRecord();

// }

// //多线程非空表插入
// int main()
// {
//     table* m_table=table::GetTable(true);

//     m_table->DisplayAllRecord();

//     CLExecutiveFunctions* Insert1=new CLExecutiveFunctionInsert(m_table);
//     CLExecutiveFunctions* Insert2=new CLExecutiveFunctionInsert(m_table);
//     CLThread *pThread1=new CLThread(Insert1);
//     CLThread *pThread2=new CLThread(Insert2);
//     pThread1->Run();
//     pThread2->Run();
//     pThread1->WaitForDeath();
//     pThread2->WaitForDeath();

//     m_table->DisplayAllRecord();

// }

// //无索引范围查询
// int main()
// {
//     table* m_table=table::GetTable(1000);
//     CLExecutiveFunctions* Search=new CLExecutiveFunctionSearch(m_table, 10, 1000, 4);
//     CLThread *pThread=new CLThread(Search);
//     pThread->Run();
//     pThread->WaitForDeath();
// }

// //有索引范围查询
// int main()
// {
//     table* m_table=table::GetTable(1000);
//     CLExecutiveFunctions* Search=new CLExecutiveFunctionSearch(m_table, 10, 1000, 4);
//     CLThread *pThread=new CLThread(Search);
//     pThread->Run();
//     pThread->WaitForDeath();
// }

// //无索引精确查询
// int main()
// {
//     table* m_table=table::GetTable(1000);
//     CLExecutiveFunctions* Search=new CLExecutiveFunctionSearch(m_table, 1000, 1000, 4);
//     CLThread *pThread=new CLThread(Search);
//     pThread->Run();
//     pThread->WaitForDeath();
// }


//有索引精确查询
int main()
{
    table* m_table=table::GetTable(false);
    CLExecutiveFunctions* Search=new CLExecutiveFunctionSearch(m_table, 1000, 1000, 4);
    CLThread *pThread=new CLThread(Search);
    pThread->Run();
    pThread->WaitForDeath();
}
