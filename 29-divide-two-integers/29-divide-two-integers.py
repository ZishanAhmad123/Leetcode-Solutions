class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # sepcial case when the dividend is zero
        if dividend == 0: return 0
        
        # find the sign be xor operation
        sign = 1
        if (dividend < 0) != (divisor < 0):
            sign = -1
        
        # find the number of possible divisions wo sign
        dividend, divisor = abs(dividend), abs(divisor)
        
        # find no of divisions
        res = self.get_division(dividend, divisor)
        
        # give sign back
        res *= sign
        
        # return results considerung boundaries
        return min(2**31-1, max(-2**31, res))
        
    def get_division(self, dividend: int, divisor: int,
                     start: int = 0) -> int:
        # find the possible number of divisions
        # using bitshifting and recursion
        res = 0
        i = 0
        next_divisor = divisor
        while dividend >= next_divisor:
            dividend -= next_divisor
            res += 1 << i
            i += 1
            next_divisor = divisor << i
        if dividend < divisor:
            return res + start
        else:
            return self.get_division(dividend, divisor, res + start)