/**
	������������ ���� �������� ����մϴ�.
	@param building ����
*/
int PK_����_��������(Building building)
{
	return -(building.���� * (rand(6) + 5) / 100);
}

/**
	������������ ġ�� �������� ����մϴ�.
	@param building ����
*/
int PK_����_ġ������(Building building)
{
	return -(2 + rand(3));
}

/**
	������������ ���� ���� ����մϴ�.
	@param building ����
	@param person �ǰ� ������ ����
	@return #��Id
*/
int PK_����_�����(Building building, Person person)
{
	if (randbool(8))
		return ��_����;
	else if (randbool(2))
		return ��_����;
	else
		return -1;
}