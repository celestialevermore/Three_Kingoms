/**
	���� ����
*/
bool PK_�����ĺ���(Person left, Person right)
{
	if (!isalive(left) || !isalive(right))
		return left.p < right.p;

	if ((left.isKunshu() && !right.isKunshu()) || (!left.isKunshu() && right.isKunshu()))
		return left.isKunshu();

	if (left.���� != right.����)
		return left.���� > right.����;

	if (left.���� != right.����)
		return left.���� < right.����;

	if (left.��� != right.���)
		return left.��� > right.���;

	return left.p < right.p;
}