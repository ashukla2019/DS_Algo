/*
Every valid email consists of a local name and a domain name, separated by the '@' sign.
Besides lowercase letters, the email may contain one or more '.' or '+'.

For example, in "alice@leetcode.com", "alice" is the local name, and "leetcode.com" 
is the domain name. If you add periods '.' between some characters in the local name
part of an email address, mail sent there will be forwarded to the same address without
dots in the local name. Note that this rule does not apply to domain names.

For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email
address. If you add a plus '+' in the local name, everything after the first plus sign
will be ignored. This allows certain emails to be filtered. Note that this rule does not
apply to domain names.
*/
int numUniqueEmails(vector<string>& emails)
{
	for(auto& email:emails)
	{
		auto at_location = find(email.begin(),email.end(),'@');
		auto end_after_removing_dots = remove(email.begin(),at_location,'.');
		auto plus_location = find(email.begin(),end_after_removing_dots,'+');
		email.erase(plus_location,at_location);
	}
	return unordered_set(emails.begin(),emails.end()).size();
}