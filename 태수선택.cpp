/**
	�¼� ����
*/
bool PK_�¼��ĺ���(Person left, Person right)
{
	if (!isalive(left) || !isalive(right) || left == right)
		return left.p < right.p;

	if ((left.�ź� <= �ź�_���� || right.�ź� <= �ź�_����) && left.�ź� != right.�ź�)
		return left.�ź� < right.�ź�;

	if (left.���� != right.����)
		return left.���� > right.����;

	if (left.��� != right.���)
		return left.��� > right.���;

	if (left.���� != right.����)
		return left.���� > right.����;

	if (left.���� != right.����)
		return left.���� > right.����;

	return left.getId() < right.getId();
}