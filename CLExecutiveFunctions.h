#ifndef CLEXECUTIVEFUNCTIONS_H
#define CLEXECUTIVEFUNCTIONS_H

#include "table.h"


//执行体功能的基类
class CLExecutiveFunctions
{
    public:
        CLExecutiveFunctions(){};
        virtual ~CLExecutiveFunctions(){};
    public:
        virtual void RunExecutiveFunction()=0;
};


class CLExecutiveFunctionSearch : public CLExecutiveFunctions
{
    public:
        CLExecutiveFunctionSearch(int left,int right,int col){
            m_left=left;
            m_right=right;
            m_col=col;
        };
        virtual ~CLExecutiveFunctionSearch(){};
        virtual void RunExecutiveFunction(){
            table* m_table=table::GetTable();
            m_table->SearchRecord(m_left,m_right,m_col);
        };

    private:
        //查询信息
        int m_left;
        int m_right;
        int m_col;
};


class CLExecutiveFunctionInsert : public CLExecutiveFunctions
{
    public:
        CLExecutiveFunctionInsert(){};
        virtual ~CLExecutiveFunctionInsert(){};
        virtual void RunExecutiveFunction(){
            table* m_table = table::GetTable();
            m_table->InsertRecord();
        };
};

#endif // CLEXECUTIVEFUNCTIONS_H
