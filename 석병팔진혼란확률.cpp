/**
	�������� ȥ�� Ȯ���� ����մϴ�.
	@param unit �δ�
*/
int PK_��������ȥ��Ȯ��(Unit unit)
{
	return int((1.0 - (unit.���� * unit.���� * 0.0001)) * 100.0 + hachijin_character_factor(Person(unit.����).����));
}

int hachijin_character_factor(int character)
{
	switch (character)
	{
	case ����_�ҽ�: return 20;
	case ����_����: return 10;
	case ����_���: return 5;
	case ����_����: return 0;
	}
	return 0;
}