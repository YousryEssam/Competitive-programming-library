long long Round(long long x, long long y) 
{ 
    if (x >= 0) return (x + y / 2) / y; 
    else return (x - y / 2) / y; 
}

long long Ceil(long long x, long long y) { return (x + y - 1) / y; }