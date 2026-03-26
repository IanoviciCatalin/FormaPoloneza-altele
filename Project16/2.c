int st[10];
int vf = -1;

int push(int k)
{
	st[++vf] =  k;
	return k;
}

int pop()
{
	return st[vf--];
}

int top()
{
	return st[vf];
}

int main()
{
	int k = 1;
	for (int i = 0; i < 8; i++)
	{
		push(i);
	}

}