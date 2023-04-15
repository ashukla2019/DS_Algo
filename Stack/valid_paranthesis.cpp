/*Valid Parenthesis:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if 
the input string is valid. An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order */
 
bool isValid(string s) 
{
	stack<char> stk;
	for(const auto& c : s)
	{
		switch(c)
		{
			case '{':  stk.push('}'); break;
			case '[':  stk.push(']'); break;
			case '(':  stk.push(')'); break;
			default:
				if(stk.size() == 0 || c != stk.top())
				{
					return false;
				}
				else 
				{
					stk.pop();
				}
		}
	}
	return stk.size() == 0;
}

