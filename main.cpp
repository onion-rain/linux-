#include <iostream>
#include<string>
#include<stdlib.h>
#include "table.h"
#include "CLThread.h"
#include "CLExecutiveFunctions.h"

int main()
{
    //测试
    table* m_table=table::GetTable();
    m_table->InsertRecord();
    //m_table->SearchRecord(800,1000,1);
    //m_table->SearchRecord(1702,1702,4);
    //CLExecutiveFunctions* inserter=new CLExecutiveFunctionInsert();
    CLExecutiveFunctions* Search=new CLExecutiveFunctionSearch(10, 1000, 8);
    CLThread *pThread=new CLThread(Search);
    pThread->Run();
    pThread->WaitForDeath();
}
