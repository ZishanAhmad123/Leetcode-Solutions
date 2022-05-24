class Solution 
{
public:
    int getLucky(string& s, int k) 
    {
        int sum = 0;
        for (char c : s)
        {
            sum += sumDigits(c - 'a' + 1);
        }
        k--;
        
        while (k)
        {
            sum = sumDigits(sum);
            k--;
        }
        
        return sum;
    }
private:
    int sumDigits(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};