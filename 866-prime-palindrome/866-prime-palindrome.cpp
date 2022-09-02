class Solution
{
    public:
        bool isPrime(int n)
        {
            if (n <= 1) return false;
            if (n <= 3) return true;
            if (n % 2 == 0 || n % 3 == 0) return false;
            for (int i = 5; i * i <= n; i = i + 6)
                if (n % i == 0 || n % (i + 2) == 0) return false;
            return true;
        }

    bool isPalindrome(string S)
    {
        string P = S;
        reverse(P.begin(), P.end());
        if (S == P)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int primePalindrome(int n)
    {
        if (99899 * 1e2 <= n && n <= 1e8)
            return 100030001;
        for (int j = n; j < 1e8; j++)
        {
            if (isPrime(j))
            {
                if (isPalindrome(to_string(j)))
                    {
                        return j;
                    }
                }
            }
            return 0;
        }
    };