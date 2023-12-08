class Solution 
{
public:
    int totalMoney(int n) 
    {
        int weekSum = 28;
        int weeks = n / 7;
        int days = n % 7;
        return (weekSum+weekSum+7*(weeks-1))*weeks/2 + (1+weeks+1+weeks+days-1)*days/2;        
    }
};


class Solution2 //to slow
{
public:
    int totalMoney(int n) 
    {
        int ret = 0;
        int weekSum = 28;
        int weeks = n / 7;
        int days = n % 7;


        return (weekSum+weekSum+weeks-1)*weeks/2 + (1+weeks+1+weeks+days-1)*days/2;        
    }
};