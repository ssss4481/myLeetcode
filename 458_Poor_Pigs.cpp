class Solution 
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) 
    {
        int level = minutesToTest/minutesToDie;
        int result = pow(2, level);
        int pig = 0;
        while(buckets > 0)
        {
            ++pig;
            buckets -= result;
        }

        return pig;        
    }

    int pow(int base, int power)
    {
        if(power == 0)
        {
            return 1;
        }
        if(power == 1)
        {
            return base;
        }

        if(power & 1 == 1)
        {
            return base * pow(base*base, power/2);
        }
        else
        {
            return pow(base*base, power/2);            
        }
    }

};