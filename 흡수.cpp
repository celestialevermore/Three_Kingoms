/**
	���� ����
	@param base	����
	@param unit	������ �δ�
				�ǹ��� �ǹ��� ������ ���ɽ�Ų ��쵵 Ȯ���ϴ� �ڵ尡 �ִµ�
				�׷� ���� �����Ƿ� �δ�� �������׽��ϴ�.
				Ȥ�� ���߿� ����� ���� ������ �����Ͻñ� �ٶ��ϴ�.
*/
void PK_���(Building base, Unit unit)
{
	Person leader;
	if (isalive(unit))
		leader = unit.����;

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	/*
	int n = 5;
	if (isalive(leader))
		n = std::max(leader.�ŷ� / 10, 5);
	*/
	int n = 70;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	base.setGold(base.�� * n / 100);
	base.setFood(base.���� * n / 100);
	base.setTroops(base.���� * n / 100);
	if (base.���� == 0)
		base.setEnergy(0);
	for (int i = 0; i < ����_��; i++)
		base.setWeapons(i, base.����[i] * n / 100);

	City city(base.toCity());
	if (!isalive(city))
		return;

	int city_force_id = city.getForceId();
	int city_id = city.getId();
	List<Building> gov;

	auto i = Scenario().�ǹ�.begin();
	for (auto j = i++; j; j = i ? i++ : i)
	{
		if (!isalive(j()))
			continue;

		// �����ü�
		if (j().isGovernmentFacility())
		{
			if (j().getAreaCityId() != city_id)
				continue;

			// �Ǽ����̴� �����ü��� ��� �ı�
			if (!j().�Ǽ��Ϸ�)
			{
				// ���۴븦 �Ǽ����̾��ٸ� ������ �����
				if (j().�ü� == �ü�_���۴�)
				{
					Item item(����_����);
					if (isalive(item))
						item.mitoujou();
				}

				Scenario().removeBuilding(j());
			}
			else
			{
				if (j().�ü� != �ü�_���۴�)
					gov.push_back(j());
			}
		}
		// ����ü�
		else if (j().isMilitaryFacility())
		{
			if (!����Id_isValid(city_force_id) || city_force_id != j().getForceId() || j().getAreaCityId() != city_id)
				continue;

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			int distance = Map().getDistance(city.getPos(), j().getPos());
			int n = 0;

			if (distance <= 4)
				n = 75;
			else if (distance <= 8)
				n = 50;
			else
				n = 30;

			if (randbool(n))
			{
				j().changeDistrict(unit.getDistrictId(), 0);
				continue;
			}
			else if (randbool(20))
			{
				continue;
			}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

			Scenario().removeBuilding(j());
		}
	}

	int charisma = 20;
	if (isalive(leader))
		charisma = leader.�ŷ�;

	n = gov.size() - std::min(charisma / 20, gov.size());

	// ������ �����ߴٸ� ��� �����ü� �ı�
	if (!�Ϲݼ���Id_isValid(unit.����))
		n = gov.size();

	gov.shuffle();
	for (int i = 0; i < n; i++)
		Scenario().removeBuilding(gov[i]);
}