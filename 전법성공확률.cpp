/**
	���� ���� Ȯ���� ����մϴ�.
	@param unit �δ�
	@param pos ��ǥ
	@param target ��ǥ ������Ʈ
	@param tactics_id #����Id
*/
int PK_��������Ȯ��(Unit unit, Point pos, HexObject target, int tactics_id)
{
	if (target.isInstance(kTypeIdUnit) && Unit(target).���� != �δ����_���)
		return 100;

	int result = ��Ÿxml().������������Ȯ�����ʽ�[unit.����];
	Point temp;

	switch (tactics_id)
	{
	case ����_����:
	case ����_����:
		result += height_diff_push_factor(height_diff(unit, target)) + 70;
		break;

	case ����_�̴�÷:
		result += height_diff_push_factor(height_diff(unit, target)) + 60;
		temp = Map().getNeighbor(target.getPos(), Map().getDirection(unit.getPos(), target.getPos()));
		result += cutoff_diff(height_diff(target.getPos(), temp));
		break;

	case ����_����:
		result += height_diff_pull_factor(height_diff(unit, target)) + 70;
		temp = Map().getNeighbor(unit.getPos(), Map().getDirection(target.getPos(), unit.getPos()));
		result += cutoff_diff(height_diff(unit.getPos(), temp));
		break;

	case ����_����÷:
	case ����_Ⱦġ:
	case ����_����:
		result += 70;
		break;

	case ����_ȭ��:
		result += ȭ��_����factor(Hex(target.getPos()).����) + 75;
		break;

	case ����_����:
		result += height_diff_push_factor(height_diff(unit, target)) + 65;
		break;

	case ����_����:
		result += height_diff_push_factor(height_diff(unit, target)) + 60;
		temp = Map().getNeighbor(target.getPos(), Map().getDirection(unit.getPos(), target.getPos()));
		result += cutoff_diff(height_diff(target.getPos(), temp));
		break;

	case ����_��ǳ:
	case ����_����:
	case ����_�Լ��ݵ�:
		result += 65;
		break;

	default:
		return 100;
	}

	return std::min(result + ����xml(unit.����).��������Ȯ�����ʽ�, 100);
}

int height_diff(Point src, Point dst)
{
	return HeightMap(coordconv().hex2heightmap(src) + 2).���� - HeightMap(coordconv().hex2heightmap(dst) + 2).����;
}

int height_diff(HexObject src, HexObject dst)
{
	return height_diff(src.getPos(), dst.getPos());
}

int cutoff_diff(int value)
{
	// ��뺸�� ����
	if (value >= 10)
		return 10;
	// ��뺸�� ����
	else if (value >= 5)
		return 5;
	// ����
	else if (value >= -5)
		return 0;
	// ��뺸�� ����
	else if (value >= -10)
		return -5;
	// ��뺸�� ����
	return -10;
}

int height_diff_push_factor(int value)
{
	return cutoff_diff(value) + 5;
}

int height_diff_pull_factor(int value)
{
	return 5 - cutoff_diff(value);
}

int ȭ��_����factor(int terrain)
{
	switch (terrain)
	{
	case ����_�ʿ�: return 0;
	case ����_��: return -5;
	case ����_��: return -5;
	case ����_����: return -15;
	case ����_��õ: return -15;
	case ����_��: return +10;
	case ����_��: return -10;
	case ����_��: return -10;
	case ����_�ٴ�: return -10;
	case ����_Ȳ����: return 0;
	case ����_�ֿ䵵��: return 0;
	case ����_������: return 0;
	case ����_�ٸ�: return 0;
	case ����_��������: return -10;
	case ����_�ؾ�: return 0;
	case ����_���: return 0;
	case ����_����: return 0;
	case ����_����: return 0;
	case ����_�ױ�: return 0;
	case ����_������: return -5;
	}
	return 0;
}