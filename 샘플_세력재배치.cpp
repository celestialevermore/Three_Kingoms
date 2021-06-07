namespace �������ġ {

Main main;

class Main
{
	Main()
	{
		regtrg(�̺�Ʈ2_�����ʱ�ȭ, Ʈ����_�ʼ��̺�Ʈ, TriggerCallbackType2(callback));
	}

	bool callback(trgevent2 e)
	{
		if (!Scenario().�ҷ����� && Scenario().��ȣ == 7)
		{
			array<string> items = { "��", "�ƴϿ�" };
			if (MessageBox().choose(items, "������ ���ġ �Ͻðڽ��ϱ�?") != 0)
				return false;
		}
		else
		{
			return false;
		}

		List<Force> forces;
		array<int> count;
		std::Random random(win32api::GetTickCount());

		forces.init();
		forces.shuffle();
		for (auto force = forces.begin(); force; force++)
			count.insertLast(force().���ü�);

		// ���� ���ġ
		Partition partition(count);
		for (int i = 0; i < forces.size(); i++)
		{
			List<City> a(���üӼ�_����, forces[i].getId()); // ���ʿ��� ����
			List<City> b; // �ʿ��� ����

			for (int j = 0; j < ����_��; j++)
			{
				if (partition.result[j] == i)
				{
					if (a.find(j))
						a.erase(j);
					else
						b.push_back(j);
				}
			}

			a.shuffle();
			b.shuffle();

			for (int j = 0; j < a.size(); j++)
			{
				Building ab = a[j].toBuilding();
				Building bb = b[j].toBuilding();
				BuildingContext ac(ab);
				BuildingContext bc(bb);
				ac.move(bb);
				bc.move(ab);

				// Ȳ�� �缳��
				if (i == 0 && j == 0)
				{
					int building_id = bb.getId();

					Person(����_����).setService(building_id);
					Person(����_����).setLocation(building_id);
					Person(����_����).setMibun(�ź�_���);

					Person(����_����).setService(building_id);
					Person(����_����).setLocation(building_id);
					Person(����_����).setMibun(�ź�_���);

					Person(����_����).setService(building_id);
					Person(����_����).setLocation(building_id);
					Person(����_����).setMibun(�ź�_���);

					switch (random(3))
					{
					case 0: Person(����_����).setMibun(-1); Scenario().setEmperor(����_����); break;
					case 1: Person(����_����).setMibun(-1); Scenario().setEmperor(����_����); break;
					case 2: Person(����_����).setMibun(-1); Scenario().setEmperor(����_����); break;
					}
				}
			}
		}

		// ����, �ױ� �缳��
		for (int i = 0; i < ����_��; i++)
		{
			City city(i);
			for (int j = 0; j < 5; j++)
			{
				if (city.����[j] == -1)
					continue;
				Building building(city.����[j]);
				if (city.getForceId() == -1)
				{
					BuildingContext context;
					context.move(building);
				}
				else
				{
					BuildingContext context;
					context.force_id = city.getForceId();
					context.district_id = city.getDistrictId();
					context.gold = city.�� / 10;
					context.food = city.���� / 10;
					context.troops = city.���� / 10;
					context.energy = city.���;
					context.weapons[random(����_â, ����_����)] = context.troops;
					context.move(building);
				}
			}
		}

		return false;
	}
};

class Partition
{
	array<int> result(����_��);
	array<int> start;
	std::Random random(win32api::GetTickCount());

	/**
		@param count ���� �� �迭
	*/
	Partition(const array<int> &in count)
	{
		// ���� ����(start)�� �������� ������ �̿� ���ø� �������� count ����ŭ ����. �����Ҷ����� �ݺ�.
		// ������ ��������� ���ð� 42���� �ۿ� �ȵǱ� ������ ������ ����.
		bool retry = true;
		do {
			// �ʱ�ȭ
			this.start.resize(����_��);
			for (int i = 0; i < ����_��; i++)
			{
				this.start[i] = i;
				this.result[i] = -1;
			}

			// ���� ���� ����
			this.shuffle(this.start);

			retry = false;
			for (int i = 0; i < count.length(); i++)
			{
				// �����ߴٸ� ó������ �ٽ�
				if (this.spread(this.start[0], count[i], i) != 0)
				{
					retry = true;
					break;
				}
			}
		} while (retry);
	}

	/**
		city_id ���ø� �������� n ���� ���ø�ŭ ����
		@return ���� ����
	*/
	int spread(int city_id, int n, int index)
	{
		// �����ų� �̹� �ٸ� ������ ������ ��� ����.
		if (n <= 0 || this.result[city_id] != -1)
			return n;

		this.result[city_id] = index;
		n -= 1;

		int pos = this.start.find(city_id);
		if (pos >= 0)
			this.start.removeAt(pos);

		// �̿����� ����.
		City city(city_id);
		array<int> neighbor_city_id(6);
		for (int i = 0; i < 6; i++)
			neighbor_city_id[i] = city.�̿�[i];
		this.shuffle(neighbor_city_id);

		for (int i = 0; i < 6; i++)
		{
			if (neighbor_city_id[i] != -1 && this.result[neighbor_city_id[i]] == -1)
				n = this.spread(neighbor_city_id[i], n, index);
			if (n == 0)
				break;
		}

		// ���� ���� ���� ����
		return n;
	}

	/***/
	void shuffle(array<int>& arr)
	{
		int n = arr.length();
		for (int i = 0; i < n; i++)
		{
			int j = this.random(n);
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
};

class BuildingContext
{
	int force_id = -1;
	int district_id = -1;
	List<Person> officers;
	int gold = 0;
	int food = 0;
	int hp = 0;
	int public_order = 0;
	int troops = 0;
	int energy = 0;
	array<int> weapons(����_��, 0);
	private Building target;

	BuildingContext() {}

	BuildingContext(Building building)
	{
		int building_id = building.getId();
		force_id = building.getForceId();
		district_id = building.getDistrictId();
		if (����Id_isValid(force_id))
		{
			officers.init(����Ӽ�_����, force_id);
			officers.remove_all_but(����Ӽ�_�Ҽ�, building.getId());
		}
		gold = building.��;
		food = building.����;
		// hp = building.����;
		if (building_id >= 0 && building_id < ����_��)
			public_order = building.toCity().ġ��;
		troops = building.����;
		energy = building.���;
		for (int i = 0; i < ����_��; i++)
			weapons[i] = building.����[i];
	}

	void move(Building building)
	{
		target = building;
		int building_id = building.getId();
		if (force_id != -1)
		{
			if (building_id >= �ǹ�_����_���� && building_id < �ǹ�_����_��)
				building.toCity().���� = district_id;
			if (building_id >= �ǹ�_����_���� && building_id < �ǹ�_����_��)
				building.toGate().���� = district_id;
			if (building_id >= �ǹ�_�ױ�_���� && building_id < �ǹ�_�ױ�_��)
				building.toPort().���� = district_id;
		}
		for (auto officer = officers.begin(); officer; officer++)
		{
			officer().setService(building_id);
			officer().setLocation(building_id);
		}
		building.setGold(gold);
		building.setFood(food);
		// building.setHP(hp);
		if (building_id >= 0 && building_id < ����_��)
			building.toCity().setPublicOrder(public_order);
		building.setTroops(troops);
		building.setEnergy(energy);
		for (int i = 0; i < ����_��; i++)
			building.setWeapons(i, weapons[i]);
	}

	// �� �۾��� move �Լ����� �ϸ� �ȵ�.
	~BuildingContext()
	{
		if (target)
		{
			if (force_id == -1)
			{
				target.neutralize();

				/*
				int building_id = target.getId();
				if (building_id >= �ǹ�_����_���� && building_id < �ǹ�_����_��)
					target.toCity().���� = district_id;
				if (building_id >= �ǹ�_����_���� && building_id < �ǹ�_����_��)
					target.toGate().���� = district_id;
				if (building_id >= �ǹ�_�ױ�_���� && building_id < �ǹ�_�ױ�_��)
					target.toPort().���� = district_id;
				*/
			}
			else
			{
				target.updateTaishu();
			}
		}
	}
};

} // namespace