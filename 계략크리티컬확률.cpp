/**
	�跫 ũ��Ƽ�� Ȯ���� ����մϴ�.
	@param src ���� �δ�
	@param src_pos ���� ��ǥ
	@param dst_pos ��ǥ ��ǥ
	@param strategy #�跫Id
*/
int PK_�跫_ũ��Ƽ��Ȯ��(Unit src, Point src_pos, Point dst_pos, int strategy)
{
	if (!isalive(src) || !Map().isValidPos(src_pos) || !Map().isValidPos(dst_pos))
		return 0;

	int src_int = src.����;
	int dst_int = 0;

	Hex dst_hex(dst_pos);
	if (dst_hex.hasUnit())
		dst_int = dst_hex.getUnit().����;

	// �Ϲ� �跫
	if (strategy >= 0 && strategy <= �跫_���� && strategy != �跫_��ȭ)
	{
		// �Ż� Ư�� ����
		if (src.hasSkill(Ư��_�Ż�))
			return 100;
		// �ɸ� Ư�� ����
		if (src.hasSkill(Ư��_�ɸ�))
			return 100;
		// ��� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
		if (src.getBestMemberStat(Ư��_����, ����ɷ�_����) > dst_int)
			return 100;
		// ��å Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
		int i = src.getBestMemberStat(Ư��_��å, ����ɷ�_����);
		if (i > -1 && i < dst_int)
			return 100;
	}

	switch (strategy)
	{
	case �跫_ȭ��:
		return std::max((src_int - dst_int / 2) / 10, 3);

	case �跫_��ȭ:
		return 0;

	case �跫_����:
		return std::max((src_int + ����ũ��_����factor(Person(src.����).����) - dst_int / 2) / 10, 3);

	case �跫_����:
		return std::max((src_int + ����ũ��_����factor(Person(src.����).����) - dst_int / 2) / 10, 3);

	case �跫_����:
		return std::max((src_int / 10), 3);

	case �跫_����:
		if (src.hasSkill(Ư��_�ź�))
			return 100;
		return std::max((src_int + ����ũ��_����factor(src.getWeaponId(src_pos)) - dst_int / 2) / 10, 3);

	case �跫_����:
		return std::max((src_int + ����ũ��_�Ǹ�factor(Person(src.����).�Ǹ�) - dst_int / 2) / 10, 3);

	case �跫_���:
	case �跫_����:
		return std::max((src_int / 12), 3);
	}

	return 0;
}

int ����ũ��_����factor(int id)
{
	switch (id)
	{
	case ����_�ҽ�: return 10;
	case ����_����: return 5;
	case ����_���: return 0;
	case ����_����: return -5;
	}
	return 0;
}

int ����ũ��_����factor(int id)
{
	switch (id)
	{
	case ����_�ҽ�: return -5;
	case ����_����: return 0;
	case ����_���: return 5;
	case ����_����: return 10;
	}
	return 0;
}

int ����ũ��_����factor(int id)
{
	switch (id)
	{
	case ����_â:
	case ����_��: return 10;
	case ����_��:
	case ����_��: return 5;
	}
	return 0;
}

int ����ũ��_�Ǹ�factor(int id)
{
	switch (id)
	{
	case �Ǹ�_�ſ쳷��: return 10;
	case �Ǹ�_����: return 5;
	case �Ǹ�_����: return 0;
	case �Ǹ�_����: return -5;
	case �Ǹ�_�ſ����: return -10;
	}
	return 0;
}