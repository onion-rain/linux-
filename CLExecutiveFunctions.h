#ifndef CLEXECUTIVEFUNCTIONS_H
#define CLEXECUTIVEFUNCTIONS_H

#include "table.h"

//执行体功能的接口类，线程业务逻辑的提供者
class CLExecutiveFunctionProvider{
    public:
        CLExecutiveFunctionProvider(){}
        virtual ~CLExecutiveFunctionProvider(){}
    public:
        virtual void RunExecutiveFunction()=0;
};


//执行体的接口类
class CLExecutive{
    public:
        explicit CLExecutive(CLExecutiveFunctionProvider* pExecutiveFunctionProvider){
            m_pExecutiveFunctionProvider=pExecutiveFunctionProvider;
        }
        virtual ~CLExecutive(){}
        virtual void Run()=0;
        virtual void WaitForDeath()=0;

    protected:
        CLExecutiveFunctionProvider* m_pExecutiveFunctionProvider;

};


class CLExecutiveFunctionSearch:public CLExecutiveFunctionProvider{
    public:

        CLExecutiveFunctionSearch(int left,int right,int col){
            m_left=left;
            m_right=right;
            m_col=col;
        }
        virtual ~CLExecutiveFunctionSearch(){}
        virtual void RunExecutiveFunction(){
            table* m_table=table::GetTable();
            m_table->SearchRecord(m_left,m_right,m_col);
        }

    private:
        //查询信息
        int m_left;
        int m_right;
        int m_col;
};


class CLExecutiveFunctionInsert: public CLExecutiveFunctionProvider {
    public:
        CLExecutiveFunctionInsert() {}

        virtual ~CLExecutiveFunctionInsert() {}

        virtual void RunExecutiveFunction() {
            table* m_table = table::GetTable();
            m_table->InsertRecord();
        }
};

#endif // CLEXECUTIVEFUNCTIONS_H
