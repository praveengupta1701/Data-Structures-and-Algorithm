

class A

{
	int *var;
public:

	int add(int a,int b)
	{
		return a+b;
	}
float add(int a,float b)
	{
		return a+b;
	}
	int add(int a,int b,int c)
	{
		return a+b+c;
	}

	A (const A &obj)
	{
		var=new int;
		*var=*(obj.var);
	}
	~A()
	{
		delete var;
	}

};


int main()
{


	A obj1;
	A obj2=obj1;//copy constr
}



class Test
{
	int k;

	virtual void show(int a): k=a
	{
	std::cout<<"this is test class";
	}
		
};


main()
{
	Test i;
	i.show(8);
}