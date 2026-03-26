int st[10];
int vf = -1;
int manna_pnueli(int x)
{
		if (x >= 12)
			pop();
		else
		{
			push(k);
			x += 2;
			manna_pnueli(x);
		}
}
/*
Folositi stiva (comprimare):
"aaabbbccd" -> 3a3b2c1d -> aaabbbccd si invers
*/
int push(k)
{
	st[++vf] = k;
	return k;
}

int pop()
{
	return st[vf--];
}

int main()
{
	int x= 6;
	manna_pnueli(x);
}