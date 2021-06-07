/**
	���� �� ����
	@param city ����
*/
int PK_����_�ݼ���(City city)
{
	if (!isalive(city) || !����Id_isValid(city.getForceId()))
		return 0;

	int result = city.�ݼ���;

	for (int i = 0; i < city.��������; i++)
	{
		Building building = city.������[i].�ǹ�;
		if (!isalive(building))
			continue;

		int facility_id = building.�ü�;
		switch (facility_id)
		{
		case �ü�_����:
		case �ü�_�����:
		case �ü�_�����:
		case �ü�_�Ͻ���:
			if (!building.�Ǽ��Ϸ�)
				continue;
			break;

		case �ü�_����2��:
			if (!building.�Ǽ��Ϸ�)
				facility_id = �ü�_����;
			break;

		case �ü�_����3��:
			if (!building.�Ǽ��Ϸ�)
				facility_id = �ü�_����2��;
			break;

		default:
			continue;
		}

		Facility facility(facility_id);
		if (!isalive(facility))
			continue;

		int n = facility.�����;

		// ������ ����� ������ �ִٸ� 1.5��
		if (facility_id == �ü�_���� || facility_id == �ü�_����2�� || facility_id == �ü�_����3��)
		{
			if (func_49ed70(building.getPos(), �ü�_����))
				n = n * 3 / 2;
		}

		result += n;
	}

	result *= 100;

	switch (Scenario().���̵�)
	{
	case ���̵�_Ư��:
		if (city.isPlayer())
		{
			result *= 75;
			break;
		}
		result *= 125;
		break;

	case ���̵�_���:
		result *= 100;
		break;

	case ���̵�_�ʱ�:
		result *= 125;
		break;
	}

	result /= 100;
	result *= std::max(city.ġ��, 50);
	result /= 100;
	result /= 100;

	return result;
}

/**
	���� ���� ����
	@param city ����
	@bug �ʱ޳��̵����� ������ +-1 ������ �߻��� �� �ֽ��ϴ�.
*/
int PK_����_��������(City city)
{
	if (!isalive(city) || !����Id_isValid(city.getForceId()))
		return 0;

	int result = city.��������;

	for (int i = 0; i < city.��������; i++)
	{
		Building building = city.������[i].�ǹ�;
		if (!isalive(building))
			continue;

		int facility_id = building.�ü�;
		switch (facility_id)
		{
		case �ü�_����:
		case �ü�_���г�:
			if (!building.�Ǽ��Ϸ�)
				continue;
			break;

		case �ü�_����2��:
			if (!building.�Ǽ��Ϸ�)
				facility_id = �ü�_����;
			break;

		case �ü�_����3��:
			if (!building.�Ǽ��Ϸ�)
				facility_id = �ü�_����2��;
			break;

		default:
			continue;
		}

		Facility facility(facility_id);
		if (!isalive(facility))
			continue;

		int n = facility.�����;

		// ������ ��â�� ������ �ִٸ� 1.5��
		if (facility_id == �ü�_���� || facility_id == �ü�_����2�� || facility_id == �ü�_����3��)
		{
			if (func_49ed70(building.getPos(), �ü�_��â))
				n = n * 3 / 2;
		}
		else if (facility_id == �ü�_���г�)
		{
			n = std::max(city.����, 15000) * n / 15000;
		}

		result += n;
	}

	result *= 100;

	switch (Scenario().���̵�)
	{
	case ���̵�_Ư��:
		if (city.isPlayer())
		{
			result *= 75;
			break;
		}
		result *= 125;
		break;

	case ���̵�_���:
		result *= 100;
		break;

	case ���̵�_�ʱ�:
		result *= 125;
		break;
	}

	result /= 100;
	result *= std::max(city.ġ��, 50);
	result /= 100;
	result /= 100;

	return result;
}

/**
	����, �ױ� �� ����
	@param building ����, �ױ�
	@param value ���� �� ����
*/
int PK_����_�ݼ���(Building building, int value)
{
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	/*
	return value * 20 / 100;
	*/
	return value * 1 / 100;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
}

/**
	����, �ױ� ���� ����
	@param building ����, �ױ�
	@param value ���� ���� ����
*/
int PK_����_��������(Building building, int value)
{
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	/*
	return value * 20 / 100;
	*/
	return value * 5 / 100;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
}

// ���� �ü� �˻�
bool func_49ed70(Point pos, int facility_id)
{
	for (int i = 0; i < ����_��; i++)
	{
		Point neighbor = Map().getNeighbor(pos, i);
		if (!Map().isValidPos(neighbor))
			continue;
		Building building = Hex(neighbor).getBuilding();
		if (!isalive(building))
			continue;
		if (building.�ü� == facility_id && building.�Ǽ��Ϸ�)
			return true;
	}
	return false;
}