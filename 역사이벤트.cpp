/** Ȳ���� �� */
bool PK_�����̺�Ʈ0(bool cond)
{
	if (cond)
	{
		if (Scenario().��ȣ != 0)
			return false;
		if (Scenario().getElapsedDays() != 0)
			return false;
		if (!Person(����_�尢).isIdle())
			return false;
		if (!Person(����_�庸).isIdle())
			return false;
		if (!Person(����_�差).isIdle())
			return false;
		if (!Person(����_Ȳ����).isIdle())
			return false;
		if (!Person(����_����).isIdle())
			return false;
		if (!Person(����_���).isIdle())
			return false;
		return true;
	}

	trgmsg().setPerson(2, ����_����);
	trgmsg().setPerson(3, ����_�尢);
	trgmsg().setPerson(4, ����_Ȳ����);
	trgmsg().setPerson(5, ����_����);
	trgmsg().setPerson(6, ����_���);

	trgsound().playBgm(16);
	trgscene().move(Building(Person(����_�尢).�Ҽ�), 0);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(2);
	trgscene().fade(255);
	trgmsg(15094, ����_�尢, ����_�庸);
	trgsound().playSfx(610);
	trgmsg(15095, ����_�庸, ����_�尢);
	trgmsg(15096, ����_�差, ����_�尢);
	trgmsg(15097, ����_�尢, ����_�庸);
	trgscene().effect(18);
	trgmsg(15098, ����_Ȳ����, ����_�尢);
	trgsound().playSfx(613);
	trgmsg(15099, ����_�差, ����_����);
	trgmsg(15100, ����_�庸, ����_�尢);
	trgmsg(15101, ����_�尢, ����_�庸);
	trgscene().effect(20);
	trgmsg(15102, ����_�尢, ����_�庸);
	trgsound().playSfx(604);
	trgscene().eventStill(8);
	trgmsg(15103, ����_Ȳ����, ����_�尢);
	trgscene().closeEventStill();
	trgscene().fade(0);
	trgsleep();
	trgscene().background(-1);
	trgscene().fade(255);
	trgscene().move(Building(Person(����_����).�Ҽ�));
	trgscene().fade(0);
	trgsleep();
	trgscene().background(1, 1);
	trgscene().fade(255);
	trgmsg(15104, ����_����, ����_����);
	trgmsg(15105, ����_����, ����_����);
	trgscene().effect(18);
	trgsound().playSfx(12);
	trgmsg(15106, ����_����, ����_����);
	trgmsg(15107, ����_����, ����_����);
	trgmsg(15108, ����_����, ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(2);
	trgscene().fade(255);
	trgmsg(15109, ����_����, ����_Ȳ����);
	trgsound().playSfx(610);
	trgscene().eventStill(21);
	trgmsg(15110, ����_Ȳ����, ����_����);
	trgmsg(15111, ����_���, ����_����);
	trgmsg(15112, ����_����, ����_����);
	trgmsg(15113, ����_����, ����_Ȳ����);
	trgscene().closeEventStill();
	trgscene().fade(0);
	trgsleep();
	trgscene().background(-1);
	trgscene().fade(255);
	trgscene().eventStill(3);
	trgsound().playSfx(603);
	trgmsg(15114);
	trgscene().closeEventStill();

	return true;
}

/** ���� ���� */
bool PK_�����̺�Ʈ1(bool cond)
{
	if (cond)
	{
		if (!Person(����_��Ź).isIdle())
			return false;
		if (!Person(����_����).isIdle())
			return false;
		if (Scenario().getStartDayCount() > daycount(189, 8, 1))
			return false;
		if (daycount(189, 9, 1) > Scenario().getDayCount())
			return false;
		if (Scenario().Ȳ�� != ����_����)
			return false;
		int force_id = Person(����_��Ź).getForceId();
		if (force_id == -1)
			return false;
		if (Force(force_id).���� != ����_��Ź)
			return false;
		if (!Force(force_id).isProtectingTheEmperor())
			return false;
		if (City(����_���).getForceId() != force_id)
			return false;
		if (City(����_����).getForceId() != force_id)
			return false;
		if (Person(����_����).getForceId() != force_id)
			return false;
		return true;
	}

	trgmsg().setPerson(2, ����_����);
	trgmsg().setPerson(3, ����_����);

	trgsound().playBgm(20);
	trgscene().move(Building(Person(����_��Ź).�Ҽ�), 1200);
	trgsleep(800);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(1);
	trgscene().fade(255);
	trgscene().effect(16);
	trgmsg(15134, ����_����, ����_��Ź);
	if (Force(Person(����_��Ź).getForceId()).isPlayer())
	{
		trgchooser().setItems(15135, 15136);
		if (trgchooser().show(15137, ����_��Ź, ����_����) != 0)
		{
			trgmsg(15138, ����_��Ź, ����_����);
			return true;
		}
	}
	trgscene().effect(17);
	trgmsg(15139, ����_��Ź, ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(2);
	trgscene().fade(255);
	trgscene().effect(13);
	trgmsg(15140, ����_��Ź, ����_����);
	trgmsg(15141, ����_����, ����_��Ź);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(1);
	trgscene().fade(255);
	trgscene().effect(20);
	trgmsg(15142, ����_��Ź, ����_����);
	trgmsg(15143, ����_����, ����_��Ź);
	trgmsg(15144, ����_��Ź, ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(2);
	trgscene().fade(255);
	trgmsg(15145, ����_��Ź, ����_����);
	trgscene().effect(16);
	trgmsg(15146, ����_����, ����_��Ź);
	trgscene().fade(0);
	trgsleep(2000);
	trgscene().fade(255);
	trgscene().effect(16);
	trgmsg(15147, ����_����, ����_��Ź);
	trgmsg(15148, ����_��Ź, ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(1);
	trgscene().fade(255);
	trgmsg(15149, ����_��Ź, ����_����);
	trgmsg(15150, ����_����, ����_��Ź);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(-1);
	trgscene().fade(255);
	trgscene().eventStill(4);
	trgsound().playSfx(12);
	trgmsg(15151);
	trgscene().closeEventStill();

	Scenario().setEmperor(����_����);

	return true;
}

/** �ݵ�Ź ���� */
bool PK_�����̺�Ʈ2(bool cond)
{
	if (cond)
	{
		if (Scenario().��ȣ != 1)
			return false;
		if (Scenario().�ϼ� != 0)
			return false;
		if (!Person(����_��Ź).isIdle())
			return false;
		if (!Person(����_����).isIdle())
			return false;
		if (!Person(����_����).isIdle())
			return false;
		return true;
	}

	trgmsg().setPerson(2, ����_��Ź);
	trgmsg().setPerson(3, ����_����);
	trgmsg().setPerson(4, ����_����);
	trgmsg().setCity(0, ����_����);

	trgsound().playBgm(17);
	trgscene().move(Building(Person(����_����).�Ҽ�), 0);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(2);
	trgscene().fade(255);
	trgmsg(15152, ����_����, ����_���ĵ�);
	trgmsg(15153, ����_���ĵ�, ����_����);
	trgscene().effect(17);
	trgmsg(15154, ����_����, ����_���ĵ�);
	trgmsg(15155, ����_���ĵ�, ����_����);
	trgmsg(15156, ����_����, ����_���ĵ�);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(-1);
	trgscene().fade(255);
	trgscene().move(Building(Person(����_����).�Ҽ�), 1200);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(2);
	trgscene().fade(255);
	trgsound().playSfx(601);
	trgmsg(15157, ����_����, ����_����);
	trgscene().effect(14);
	trgmsg(15158, ����_����, ����_����);
	trgscene().eventStill(21);
	trgmsg(15159, ����_����, ����_����);
	trgsound().playSfx(11);
	trgmsg(15160, ����_����, ����_����);
	trgscene().closeEventStill();
	trgscene().fade(0);
	trgsleep();
	trgscene().background(-1);
	trgscene().fade(255);
	trgscene().move(Building(Person(����_��Ź).�Ҽ�), 800);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(1);
	trgscene().fade(255);
	trgscene().effect(18);
	trgmsg(15161, ����_����, ����_��Ź);
	trgscene().effect(13);
	trgmsg(15162, ����_��Ź, ����_����);
	trgmsg(15163, ����_����, ����_��Ź);
	trgmsg(15164, ����_��Ź, ����_����);
	trgmsg(15165, ����_����, ����_��Ź);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(-1);
	trgscene().fade(255);
	trgscene().eventStill(24);
	trgsound().playSfx(603);
	trgmsg(15166);
	trgscene().closeEventStill();

	return true;
}

/** ����, ������ �ڽ��� Ȳ����� ��Ī�ϴ�. */
bool PK_�����̺�Ʈ3(bool cond)
{
	if (cond)
	{
		if (!Person(����_����).isIdle())
			return false;
		if (Person(����_����).�ź� != �ź�_����)
			return false;
		if (30 > Scenario().getElapsedDays())
			return false;
		int force_id = Person(����_����).getForceId();
		if (Force(force_id).isProtectingTheEmperor())
			return false;
		if (Item(����_����).�������� != ����_����)
			return false;
		if (Force(force_id).���� == ����_Ȳ��)
			return false;
		if (3 > Force(force_id).���ü�)
			return false;
		if (List<Force>().init(���¼Ӽ�_��ȣ, ��ȣ_��) != 0)
			return false;
		return true;
	}

	trgmsg().setPerson(2, ����_����);
	trgmsg().setItem(0, ����_����);

	trgsound().playBgm(20);
	trgscene().move(Building(Person(����_����).�Ҽ�), 800);
	trgmsg(15433);
	trgmsg(15434, ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(1);
	trgscene().fade(255);
	trgscene().effect(17);
	trgmsg(15435, ����_����);
	int var0 = ����_����;
	if (Person(����_����).���� == ����_���� && Person(����_����).isIdle())
		var0 = ����_����;
	trgscene().effect(13);
	trgmsg(15436, var0, ����_����);
	trgmsg(15437, ����_����, var0);
	trgmsg(15438, var0, ����_����);
	if (Person(����_����).isPlayer())
	{
		trgchooser().setItems(15440, 15441);
		if (trgchooser().show(15439, ����_����) != 0)
		{
			trgmsg(15442, ����_����, var0);
			return true;
		}
	}
	trgscene().effect(20);
	trgmsg(15443, ����_����, var0);
	trgmsg(15444, var0, ����_����);
	trgmsg(15445, ����_����, var0);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(-1);
	trgscene().fade(255);
	trgscene().eventStill(4);
	trgsound().playSfx(12);
	trgmsg(15446);
	trgscene().closeEventStill();

	int force_id = Person(����_����).getForceId();

	Force(force_id).setTitle(����_Ȳ��);
	Force(force_id).setKokugou(��ȣ_��);

	List<Force> forces;
	List<Person> officers;

	officers.push_back(����_����);
	officers.push_back(����_����);
	officers.push_back(����_�հ�);
	officers.push_back(����_��å);
	officers.push_back(����_�ձ�);
	officers.push_back(����_����);
	officers.push_back(����_����);

	forces.init(���¼Ӽ�_�÷��̾�, false);
	forces.remove(force_id);
	for (auto i = forces.begin(); i; i++)
	{
		if (i().isProtectingTheEmperor() || Person(i().����).�ѽ� == �ѽ�_�߽� || officers.contains(i().����))
		{
			i().unally(force_id);
			i().setRelations(force_id, 0);
		}
	}

	forces.init(���¼Ӽ�_�÷��̾�, true);
	forces.remove(force_id);
	for (auto i = forces.begin(); i; i++)
	{
		if (!i().isEnemy(force_id) || i().��ȣ��[force_id] >= 75)
			continue;

		if (i().isProtectingTheEmperor() || Person(i().����).�ѽ� == �ѽ�_�߽� || officers.contains(i().����))
			i().addRelations(force_id, -50);
	}

	return true;
}

/** �̰� ���� */
bool PK_�����̺�Ʈ4(bool cond)
{
	if (cond)
	{
		if (!Person(����_����).isIdle())
			return false;
		if (!Person(����_����).isIdle())
			return false;
		if (Person(����_����).�ź� != �ź�_����)
			return false;
		if (Person(����_����).�ź� != �ź�_����)
			return false;
		if (Scenario().��ȣ == 3 && Scenario().getElapsedDays() == 0)
			return true;
		if (daycount(199, 12, 1) < Scenario().getDayCount())
			return false;
		if (Person(����_����).isCloseWith(����_����))
			return false;
		if (!Force(Person(����_����).getForceId()).isEnemy(Person(����_����).getForceId()))
			return false;
		List<City> list;
		list.init(���üӼ�_����, ����_�߿�);
		if (list.remove_all_but(���üӼ�_����, Person(����_����).getForceId()) < 5)
			return false;
		list.init(���üӼ�_����, ����_�Ϻ�);
		if (list.remove_all_but(���üӼ�_����, Person(����_����).getForceId()) < 5)
			return false;
		if (!Force(Person(����_����).getForceId()).hasNeighborCity(Person(����_����).getForceId()))
			return false;
		return true;
	}

	trgmsg().setPerson(2, ����_����);
	trgmsg().setPerson(3, ����_����);
	trgmsg().setPerson(4, ����_����);

	trgsound().playBgm(16);
	trgscene().move(Building(Person(����_����).�Ҽ�), 0);
	trgmsg(15447, ����_����);
	trgmsg(15448, ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(1);
	trgscene().fade(255);
	trgscene().effect(20);
	trgmsg(15449, ����_����);
	trgscene().effect(13);
	trgmsg(15450, (Person(����_��ǳ).���� == ����_���� && Person(����_��ǳ).isIdle()) ? ����_��ǳ : ����_����, ����_����);
	trgmsg(15451, (Person(����_����).���� == ����_���� && Person(����_����).isIdle()) ? ����_���� : ����_����, ����_����);
	trgscene().effect(17);
	trgmsg(15452, (Person(����_����).���� == ����_���� && Person(����_����).isIdle()) ? ����_���� : ����_����, ����_����);
	trgmsg(15453, (Person(����_�ɹ�).���� == ����_���� && Person(����_�ɹ�).isIdle()) ? ����_�ɹ� : ����_����, ����_����);
	trgmsg(15454, ����_����);
	bool var0 = Person(����_����).���� == ����_���� && Person(����_����).isIdle();
	if (var0)
	{
		trgmsg(15455, ����_����, ����_����);
		trgsound().playSfx(610);
		trgscene().eventStill(21);
		trgmsg(15456, ����_����, ����_����);
		trgmsg(15457, ����_����, ����_����);
		trgmsg(15458, ����_����, ����_����);
		trgscene().closeEventStill();
	}
	else
	{
		trgsound().playSfx(610);
		trgscene().eventStill(21);
		trgmsg(15459, ����_����, ����_õ����);
		trgmsg(15456, ����_õ����, ����_����);
		trgscene().closeEventStill();
	}
	trgscene().fade(0);
	trgsleep();
	trgscene().background(-1);
	trgscene().fade(255);
	trgscene().move(Building(Person(����_����).�Ҽ�));
	trgscene().fade(0);
	trgsleep();
	trgscene().background(1);
	trgscene().fade(255);
	trgsound().playSfx(12);
	trgmsg(15460, ����_����, ����_����);
	trgscene().effect(14);
	trgmsg(15461, ����_����, ����_����);
	if (var0)
	{
		trgscene().effect(13);
		trgmsg(15462, ����_����);
		trgmsg(15463, ����_����);
		trgscene().eventStill(21);
		trgmsg(15464, ����_����, ����_����);
		trgmsg(15465, ����_����, ����_����);
		trgmsg(15466, ����_����);
		trgscene().closeEventStill();
		trgscene().effect(20);
		trgmsg(15467, ����_����);
	}
	else
	{
		trgmsg(15468, ����_����);
	}
	trgscene().fade(0);
	trgsleep(2000);
	trgscene().background(-1);
	trgscene().fade(255);
	trgscene().eventStill(24);
	trgsound().playSfx(603);
	trgmsg(15469);
	trgscene().closeEventStill();

	Force(Person(����_����).getForceId()).setRelations(Person(����_����).getForceId(), 0);
	Force(Person(����_����).getForceId()).unally(Person(����_����).getForceId());

	return true;
}

/** ����, ���� */
bool PK_�����̺�Ʈ5(bool cond)
{
	if (cond)
	{
		if (Person(����_����).�ź� != �ź�_����)
			return false;
		if (!Person(����_����).isIdle())
			return false;
		if (Scenario().getElapsedDays() < 30)
			return false;
		int force_id = Person(����_����).getForceId();
		if (City(����_��â).getForceId() != force_id)
			return false;
		if (City(����_��).getForceId() != force_id)
			return false;
		if (City(����_�ž�).getForceId() == force_id)
			return false;
		List<City> list;
		list.init(���üӼ�_����, ����_�߿�);
		if (list.remove_all_but(���üӼ�_����, force_id) < 7)
			return false;
		list.init(���üӼ�_����, ����_�Ϻ�);
		int var0 = list.remove(����_����);
		if (list.remove_all_but(���üӼ�_����, force_id) < var0)
			return false;
		list.init(���üӼ�_����, ����_����);
		if (0 < list.remove_all_but(���üӼ�_����, force_id))
			return false;
		list.clear();
		list.push_back(����_���);
		list.push_back(����_����);
		list.push_back(����_�û�);
		list.push_back(����_�Ǿ�);
		for (auto i = list.begin(); i; i++)
		{
			if (i().getForceId() != -1 && !Force(i().getForceId()).isEnemy(force_id))
				return false;
		}
		return true;
	}

	trgmsg().setPerson(2, ����_����);

	trgsound().playBgm(17);
	trgscene().move(Building(Person(����_����).�Ҽ�));
	trgmsg(15742, ����_����, ����_����);
	trgmsg(15743, ����_����, ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(1);
	trgscene().fade(255);
	trgmsg(15744, ����_����);
	trgscene().effect(20);
	trgmsg(15745, ����_����);
	trgscene().effect(21);
	trgmsg(15746, ����_����);
	trgmsg(15747, ����_����);
	trgmsg(15748, ����_����);
	trgmsg(15749, ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(-1);
	trgscene().fade(255);
	trgscene().eventStill(24);
	trgsound().playSfx(603);
	trgmsg(15750);
	trgscene().closeEventStill();

	List<City> cities;
	cities.push_back(����_���);
	cities.push_back(����_����);
	cities.push_back(����_�û�);
	cities.push_back(����_�Ǿ�);
	for (auto i = cities.begin(); i; i++)
	{
		if (i().getForceId() == -1 || i().getForceId() == Person(����_����).getForceId())
			continue;

		Force(Person(����_����).getForceId()).unally(i().getForceId());
		Force(Person(����_����).getForceId()).setRelations(i().getForceId(), 10);
	}

	return true;
}

/** ���߿� ���� */
bool PK_�����̺�Ʈ6(bool cond)
{
	if (cond)
	{
		if (Scenario().getStartDayCount() >= daycount(218, 12, 1))
			return false;
		if (180 > Scenario().getElapsedDays())
			return false;
		if (Person(����_����).�ź� != �ź�_����)
			return false;
		int var0 = Person(����_����).getForceId();
		if (Scenario().Ȳ�� == -1)
			return false;
		if (!Person(����_����).isIdle())
			return false;
		if (!Person(����_������).isIdle())
			return false;
		if (����_�� > Force(Person(����_����).getForceId()).����)
			return false;
		if (Person(����_������).getForceId() != var0)
			return false;
		if (Force(var0).isProtectingTheEmperor())
			return false;
		if (Region(����_����).���ɼ��� != var0)
			return false;
		return true;
	}

	int var0 = Person(����_����).getForceId();

	trgmsg().setPerson(2, ����_����);
	trgmsg().setPerson(3, ����_������);

	trgsound().playBgm(16);
	trgscene().move(Building(Person(����_����).�Ҽ�));
	trgsound().playSfx(601);
	trgmsg(15841, ����_����, ����_����);
	trgmsg(15842, ����_����, ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(2);
	trgscene().fade(255);
	trgscene().effect(20);
	trgmsg(15843, ����_������, ����_����);
	trgsound().playSfx(12);
	trgmsg(15844, ����_����, ����_������);
	trgmsg(15845, ����_������, ����_����);
	trgmsg(15846, ����_����, ����_������);
	trgmsg(15847, ����_������, ����_����);
	if (Person(����_���).getForceId() == Person(����_����).getForceId() && Person(����_���).isIdle())
	{
		trgscene().effect(13);
		trgmsg(15848, ����_���, ����_����);
		trgscene().effect(20);
		trgmsg(15849, ����_����, ����_���);
	}
	trgsleep();
	trgmsg(15850, ����_����, ����_������);
	trgsound().playSfx(11);
	trgmsg(15851, ����_����, ����_������);
	trgsound().playBgm(17);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(1);
	trgscene().fade(255);
	trgmsg(15852, ����_����);
	trgscene().effect(21);
	trgmsg(15853, ����_����);
	trgmsg(15854, ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(-1);
	trgscene().fade(255);
	trgscene().eventStill(27);
	trgsound().playSfx(612);
	trgmsg(15855);
	trgscene().closeEventStill();

	Force(var0).setTitle(����_��);

	List<City> cities(���üӼ�_����, var0);
	for (auto i = cities.begin(); i; i++)
	{
		i().addPublicOrder(15);
		if (i().���� != 0)
			i().addEnergy(15);
	}

	Person(����_������).addKouseki(2000);

	List<Person> officers(����Ӽ�_����, var0);
	officers.remove(����_����);
	for (auto i = officers.begin(); i; i++)
		i().addLoyalty(15);

	List<Force> forces;
	forces.init();
	forces.remove(var0);
	forces.remove_all_but(���¼Ӽ�_�ܱ� + var0, -1);
	// forces.remove_all_but(176 + var0, 75, ������_��������);
	for (auto i = forces.begin(); i; i++)
	{
		if (i().���� == ����_���� || Person(����_����).isCloseWith(i().����) || i().isProtectingTheEmperor())
			i().addRelations(var0, -15);
	}

	return true;
}

/** ���� ���� */
bool PK_�����̺�Ʈ7(bool cond)
{
	if (cond)
	{
		if (Scenario().getStartDayCount() > daycount(219, 12, 1))
			return false;
		if (180 > Scenario().getElapsedDays())
			return false;
		if (List<Force>().init(���¼Ӽ�_��ȣ, ��ȣ_��) != 0)
			return false;
		if (Scenario().Ȳ�� == -1)
			return false;
		if (Scenario().Ȳ����ȣ���� == -1)
			return false;
		int var0 = Scenario().Ȳ����ȣ����;
		int var1 = Force(var0).����;
		if (!Person(var1).isIdle())
			return false;
		if (Person(var1).���� != Person(����_����).����)
			return false;
		if (Person(var1) == ����_����)
			return false;
		if (Force(var0).���� != ����_��)
			return false;
		if (12 > Force(var0).���ü�)
			return false;
		if (City(����_��â).getForceId() != var0)
			return false;
		if (City(����_����).getForceId() != var0)
			return false;
		if (City(����_��).getForceId() != var0)
			return false;
		if (City(����_���).getForceId() != var0)
			return false;
		List<Person> list(����Ӽ�_�ź�, �ź�_����);
		if (list.remove_all_but(����Ӽ�_����, Person(����_����).����) != 1)
			return false;
		return true;
	}

	int var0 = Scenario().Ȳ����ȣ����;
	int var1 = Force(var0).����;

	trgmsg().setPerson(2, var1);
	trgmsg().setPerson(3, Scenario().Ȳ��);

	trgsound().playBgm(20);
	trgscene().move(Building(Person(var1).�Ҽ�));
	trgscene().fade(0);
	trgsleep();
	trgscene().background(2);
	trgscene().fade(255);
	int var2 = ����_����;
	if (Person(����_ȭ��).getForceId() == var0)
		var2 = ����_ȭ��;
	trgmsg(15873, var2, var1);
	trgmsg(15874, var1, var2);
	trgscene().effect(16);
	trgmsg(15875, var2, var1);
	trgmsg(15876, var1, var2);
	trgscene().effect(17);
	trgmsg(15877, var2, var1);
	if (Force(var0).isPlayer())
	{
		trgchooser().setItems(15879, 15880);
		if (trgchooser().show(15878, var1) != 0)
		{
			trgmsg(15881, var1, var2);
			trgmsg(15882, var2, var1);
			return true;
		}
	}
	trgscene().effect(20);
	trgmsg(15883, var1, var2);
	trgmsg(15882, var2, var1);
	trgscene().fade(0);
	trgsleep(2000);
	trgscene().background(1);
	trgscene().fade(255);
	trgmsg(15884, var2, Scenario().Ȳ��);
	trgsound().playSfx(613);
	trgmsg(15885, Scenario().Ȳ��, var2);
	trgscene().effect(17);
	trgmsg(15886, var2, Scenario().Ȳ��);
	trgmsg(15887, Scenario().Ȳ��, var2);
	trgmsg(15888, var2, Scenario().Ȳ��);
	trgsound().playSfx(12);
	trgmsg(15889, Scenario().Ȳ��);
	trgscene().fade(0);
	trgsleep(2000);
	trgscene().fade(255);
	trgsound().playSfx(11);
	trgmsg(15890, var1);
	trgscene().effect(21);
	trgmsg(15891, ����_����);
	trgmsg(15892, ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(-1);
	trgscene().fade(255);
	trgscene().eventStill(4);
	trgsound().playSfx(12);
	trgmsg(15893);
	trgscene().closeEventStill();

	trgmgr().setLastRunTime(107, Scenario().getDayCount());

	Scenario().setEmperor(-1);

	Force(var0).setTitle(����_Ȳ��);
	Force(var0).setKokugou(��ȣ_��);

	List<City> cities(���üӼ�_����, var0);
	for (auto i = cities.begin(); i; i++) {
		i().addPublicOrder(20);
		if (i().���� != 0)
			i().addEnergy(20);
	}

	List<Person> officers(����Ӽ�_����, var0);
	officers.remove(var1);
	for (auto i = officers.begin(); i; i++) {
		if (i().�ѽ� == �ѽ�_�߽�)
			i().addLoyalty(-20);
		else
			i().addLoyalty(20);
	}

	List<Force> forces;
	forces.init();
	forces.remove(var0);
	forces.remove_all_but(���¼Ӽ�_�ܱ� + var0, -1);
	// forces.remove_all_but(176 + var0, 75, ������_��������);
	for (auto i = forces.begin(); i; i++) {
		if (Person(����_����).isCloseWith(i().����) || Person(i().����).�ѽ� == �ѽ�_�߽� || i().���� == ����_Ȳ��)
			i().addRelations(var0, -50);
	}

	return true;
}

/** ���� ���� */
bool PK_�����̺�Ʈ8(bool cond)
{
	if (cond)
	{
		if (Scenario().getStartDayCount() > daycount(220, 12, 1))
			return false;
		if (180 > Scenario().getElapsedDays())
			return false;
		if (Scenario().Ȳ�� != -1)
			return false;
		if (!Person(����_������).isIdle())
			return false;
		if (List<Force>().init(���¼Ӽ�_��ȣ, ��ȣ_��) != 0)
			return false;
		// ���� ���� �̺�Ʈ�� �߻��ߴٸ� 90�� �̻� ��������
		if (trgmgr().hasRun(146) && 90 > trgmgr().getElapsedDays(107))
			return false;
		int var0 = City(����_����).getForceId();
		if (var0 == -1)
			return false;
		if (Person(Force(var0).����).���� != Person(����_����).����)
			return false;
		if (Force(var0).���� != ����_Ȳ��)
			return false;
		if (8 > Force(var0).���ü�)
			return false;
		if (City(����_��).getForceId() != var0)
			return false;
		int var1 = Region(����_����).���ɼ���;
		if (var1 == -1)
			return false;
		if (!Person(Force(var1).����).isCloseWith(����_����))
			return false;
		if (Force(var1).���� != ����_��)
			return false;
		if (Person(����_������).getForceId() != var1)
			return false;
		if (Person(����_������).�ź� == �ź�_����)
			return false;
		if (Person(Force(var0).����).isCloseWith(Force(var1).����))
			return false;
		if (!Force(var0).isEnemy(var1))
			return false;
		if (Force(var0).��ȣ��[var1] >= 75)
			return false;
		if (!Person(Force(var1).����).isIdle())
			return false;
		List<Person> list(����Ӽ�_�ź�, �ź�_����);
		if (list.remove_all_but(����Ӽ�_����, Person(����_����).����) != 1)
			return false;
		return true;
	}

	int var0 = Region(����_����).���ɼ���;
	int kunshu_id = Force(var0).����;

	trgmsg().setPerson(2, kunshu_id);
	trgmsg().setPerson(3, ����_������);

	trgsound().playBgm(16);
	trgscene().move(Building(Person(kunshu_id).�Ҽ�));
	trgsound().playSfx(601);
	trgmsg(15894, ����_����, kunshu_id);
	trgmsg(15895, kunshu_id, ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(2);
	trgscene().fade(255);
	trgmsg(15896, kunshu_id, ����_������);
	trgmsg(15897, ����_������, kunshu_id);
	trgscene().effect(13);
	trgmsg(15898, kunshu_id, ����_������);
	trgmsg(15899, ����_������, kunshu_id);
	trgmsg(15900, kunshu_id, ����_������);
	trgscene().effect(20);
	trgmsg(15901, ����_������, kunshu_id);
	trgmsg(15902, kunshu_id, ����_������);
	trgscene().fade(0);
	trgsleep(2000);
	trgscene().fade(255);
	trgscene().effect(16);
	trgmsg(15903, ����_����, kunshu_id);
	trgsound().playSfx(12);
	trgmsg(15904, kunshu_id, ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(5);
	trgscene().fade(255);
	trgmsg(15905, kunshu_id, ����_������);
	trgmsg(15906, ����_������, kunshu_id);
	trgsound().playSfx(613);
	trgmsg(15907, kunshu_id, ����_������);
	trgmsg(15908, ����_������, kunshu_id);
	trgmsg(15909, kunshu_id, ����_������);
	trgscene().effect(20);
	trgmsg(15910, ����_������, kunshu_id);
	trgsleep(1500);
	trgmsg(15911, kunshu_id, ����_������);
	trgsound().playBgm(17);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(1);
	trgscene().fade(255);
	trgsound().playSfx(11);
	trgmsg(15912, kunshu_id);
	trgscene().effect(21);
	trgmsg(15913, ����_����);
	trgmsg(15914, ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(-1);
	trgscene().fade(255);
	trgscene().eventStill(4);
	trgsound().playSfx(612);
	trgmsg(15915);
	trgscene().closeEventStill();

	Force(var0).setTitle(����_Ȳ��);
	Force(var0).setKokugou(��ȣ_��);

	List<City> cities(���üӼ�_����, var0);
	for (auto i = cities.begin(); i; i++) {
		i().addPublicOrder(30);
		if (i().���� != 0)
			i().addEnergy(30);
	}

	List<Person> officers(����Ӽ�_����, var0);
	officers.remove(kunshu_id);
	officers.addLoyalty(30);

	List<Force> forces;
	forces.init();
	forces.remove(var0);
	forces.remove_all_but(���¼Ӽ�_�ܱ� + var0, -1);
	// forces.remove_all_but(176 + var0, 75, ������_��������);
	for (auto i = forces.begin(); i; i++) {
		if (i().���� == ����_���� || Person(i().����).���� == Person(����_����).���� || i().���� == ����_Ȳ��)
			i().addRelations(var0, -20);
	}

	return true;
}

/** ��, Ī�� */
bool PK_�����̺�Ʈ9(bool cond)
{
	if (cond)
	{
		if (Scenario().getStartDayCount() > daycount(221, 12, 1))
			return false;
		if (180 > Scenario().getElapsedDays())
			return false;
		if (Scenario().Ȳ�� != -1)
			return false;
		if (3 > List<Force>().init())
			return false;
		// ���� ���� �̺�Ʈ�� �߻��ߴٸ� 180�� �̻� ��������
		if (trgmgr().hasRun(146) && 180 > trgmgr().getElapsedDays(107))
			return false;
		int var0 = City(����_����).getForceId();
		if (var0 == -1)
			return false;
		if (Person(Force(var0).����).���� != Person(����_����).����)
			return false;
		if (Force(var0).���� != ����_Ȳ��)
			return false;
		if (8 > Force(var0).���ü�)
			return false;
		if (City(����_��).getForceId() != var0)
			return false;
		int var1 = Province(��_����).���ɼ���;
		if (var1 == -1)
			return false;
		if (Person(Force(var1).����).���� != Person(����_�հ�).����)
			return false;
		if (8 > Force(var1).���ü�)
			return false;
		if (����_�� > Force(var1).����)
			return false;
		if (40 > Force(var0).��ȣ��[var1])
			return false;
		if (!Person(Force(var1).����).isIdle())
			return false;
		List<Person> list;
		list.init(����Ӽ�_�ź�, �ź�_����);
		if (list.remove_all_but(����Ӽ�_����, Person(����_����).����) != 1)
			return false;
		list.init(����Ӽ�_�ź�, �ź�_����);
		if (list.remove_all_but(����Ӽ�_����, Person(����_�հ�).����) != 1)
			return false;
		return true;
	}

	int var0 = City(����_����).getForceId();
	int var1 = Province(��_����).���ɼ���;
	int var2 = ����_����;

	if (Person(����_���).getForceId() == var1 && Person(����_���).isIdle())
	{
		var2 = ����_���;
	}
	else
	{
		List<Person> list(����Ӽ�_����, var1);
		list.remove(Force(var1).����);
		if (0 < list.remove_all_but(����Ӽ�_����, true))
		{
			list.sort(����Ӽ�_�ɷ� + ����ɷ�_����, ����_��������);
			var2 = list[0].getId();
		}
	}

	trgmsg().setPerson(2, Force(var1).����);
	trgmsg().setPerson(3, var2);
	trgmsg().setPerson(4, Force(var0).����);
	trgmsg().setForce(0, var0);

	trgsound().playBgm(16);
	trgscene().move(Building(Person(Force(var1).����).�Ҽ�));
	trgsound().playSfx(601);
	trgmsg(15944, ����_����, Force(var1).����);
	trgmsg(15945, Force(var1).����, ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(2);
	trgscene().fade(255);
	trgmsg(15946, Force(var1).����, var2);
	trgscene().effect(17);
	trgmsg(15947, var2, Force(var1).����);
	trgsound().playSfx(613);
	trgmsg(15948, Force(var1).����, var2);
	trgscene().effect(20);
	trgmsg(15949, var2, Force(var1).����);
	trgmsg(15950, Force(var1).����, var2);
	trgmsg(15951, var2, Force(var1).����);
	trgscene().fade(0);
	trgsleep();
	trgsound().playSfx(11);
	trgmsg(15952);
	trgscene().fade(255);
	trgscene().background(1);
	trgmsg(15953, Force(var1).����);
	trgscene().effect(21);
	trgmsg(15954, ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(-1);
	trgscene().fade(255);
	trgscene().eventStill(27);
	trgsound().playSfx(612);
	trgmsg(15955);
	trgscene().closeEventStill();

	trgmgr().setLastRunTime(108, Scenario().getDayCount());

	Force(var1).setTitle(����_��);

	List<City> cities(���üӼ�_����, var1);
	for (auto i = cities.begin(); i; i++)
	{
		i().addPublicOrder(10);
		if (i().���� != 0)
			i().addEnergy(10);
	}

	List<Person> officers(����Ӽ�_����, var1);
	officers.remove(Force(var1).����);
	for (auto i = officers.begin(); i; i++)
		i().addLoyalty(10);

	Force(var1).addRelations(var0, 20);

	List<Force> forces;
	forces.init();
	forces.remove(var1);
	forces.remove(var0);
	forces.remove_all_but(���¼Ӽ�_�ܱ� + var1, -1);
	// forces.remove_all_but(176 + var1, 75, ������_��������);
	for (auto i = forces.begin(); i; i++)
	{
		if (Person(i().����).isCloseWith(����_����) || i().���� == ����_Ȳ��)
			i().addRelations(var1, -30);
	}
	return true;
}

/** ���ǥ */
bool PK_�����̺�Ʈ10(bool cond)
{
	if (cond)
	{
		if (!Person(����_������).isIdle())
			return false;
		if (Person(����_������).getForceId() == -1)
			return false;
		if (!Person(Force(Person(����_������).getForceId()).����).isIdle())
			return false;
		if (30 > Scenario().getElapsedDays())
			return false;
		if (Scenario().Ȳ�� != -1)
			return false;
		if (Person(����_������).�ź� == �ź�_����)
			return false;
		if (Person(����_������).�������)
			return false;
		int force_id = Person(����_������).getForceId();
		if (!Person(Force(force_id).����).isCloseWith(����_����))
			return false;
		if (Force(force_id).���� != ����_Ȳ��)
			return false;
		if (95 > City(����_����).ġ��)
			return false;
		if (95 > City(����_����).ġ��)
			return false;
		if (Region(����_����).���ɼ��� != force_id)
			return false;
		if (Region(����_����).���ɼ��� != force_id)
			return false;
		int var0 = City(����_����).getForceId();
		if (var0 == -1)
			return false;
		if (var0 == force_id)
			return false;
		if (Force(var0).���� != ����_Ȳ��)
			return false;
		if (Force(Person(����_������).getForceId()).���ü� >= Force(var0).���ü�)
			return false;
		if (City(����_��â).getForceId() != var0)
			return false;
		if (City(����_��).getForceId() != var0)
			return false;
		if (!Force(force_id).isEnemy(var0))
			return false;
		if (Person(Force(force_id).����).isCloseWith(Force(var0).����))
			return false;
		if (Force(force_id).��ȣ��[var0] >= 75)
			return false;
		return true;
	}

	int force_id = Person(����_������).getForceId();
	int var0 = City(����_����).getForceId();

	trgmsg().setPerson(2, ����_������);
	trgmsg().setForce(0, var0);

	trgsound().playBgm(16);
	trgscene().move(Building(Person(����_������).�Ҽ�));
	trgmsg(15985, ����_������, ����_����);
	trgmsg(15986, ����_����, ����_������);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(1);
	trgscene().fade(255);
	trgmsg(15987, Force(force_id).����, ����_������);
	trgscene().effect(14);
	trgmsg(15988, ����_������, Force(force_id).����);
	trgmsg(15989, Force(force_id).����, ����_������);
	trgscene().effect(10);
	trgmsg(15990, ����_������, Force(force_id).����);
	trgscene().fade(0);
	trgsleep(2000);
	trgscene().fade(255);
	trgmsg(15991, ����_������, Force(force_id).����);
	trgmsg(15992, Force(force_id).����, ����_������);
	trgmsg(15993, ����_������, Force(force_id).����);
	trgmsg(15994, Force(force_id).����, ����_������);
	trgsound().playBgm(17);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(2);
	trgscene().fade(255);
	trgmsg(15995, ����_������);
	if (Person(����_����).getForceId() == force_id && Person(����_����).isIdle())
	{
		trgscene().effect(20);
		trgmsg(15996, ����_����, ����_������);
	}
	trgmsg(15997, ����_������);
	trgscene().effect(21);
	trgmsg(15998, ����_����);
	trgmsg(15999, ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(-1);
	trgscene().fade(255);
	trgscene().eventStill(24);
	trgsound().playSfx(603);
	trgmsg(16000);
	trgscene().closeEventStill();

	Force(force_id).setRelations(var0, 0);
	Force(force_id).unally(var0);

	List<Person> officers(����Ӽ�_����, force_id);
	officers.remove(Force(force_id).����);
	officers.addLoyalty(10);

	return true;
}

/** ���� ���� */
bool PK_�����̺�Ʈ11(bool cond)
{
	if (cond)
	{
		if (Scenario().getStartDayCount() > daycount(228, 12, 1))
			return false;
		if (180 > Scenario().getElapsedDays())
			return false;
		if (Scenario().Ȳ�� != -1)
			return false;
		if (List<Force>().init(���¼Ӽ�_��ȣ, ��ȣ_��) != 0)
			return false;
		if (trgmgr().hasRun(149) && 360 > trgmgr().getElapsedDays(108))
			return false;
		if (List<Force>().init(���¼Ӽ�_����, ����_Ȳ��) < 2)
			return false;
		int var0 = Province(��_����).���ɼ���;
		if (var0 == -1)
			return false;
		if (Person(Force(var0).����).���� != Person(����_�հ�).����)
			return false;
		if (Force(var0).���� != ����_��)
			return false;
		if (8 > Force(var0).���ü�)
			return false;
		if (!Person(Force(var0).����).isIdle())
			return false;
		List<Person> officers(����Ӽ�_�ź�, �ź�_����);
		if (officers.remove_all_but(����Ӽ�_����, Person(����_�հ�).����) != 1)
			return false;
		return true;
	}

	int var0 = Province(��_����).���ɼ���;
	int var1 = ����_����;

	if (Person(����_���).getForceId() == var0 && Person(����_���).isIdle())
	{
		var1 = ����_���;
	}
	else
	{
		List<Person> officers(����Ӽ�_����, var0);
		officers.remove(Force(var0).����);
		if (0 < officers.remove_all_but(����Ӽ�_����, true))
		{
			officers.sort(����Ӽ�_�ɷ� + ����ɷ�_����, ����_��������);
			var1 = officers[0].getId();
		}
	}

	trgmsg().setPerson(2, Force(var0).����);
	trgmsg().setPerson(3, var1);

	trgsound().playBgm(16);
	trgscene().move(Building(Person(Force(var0).����).�Ҽ�));
	trgsound().playSfx(601);
	trgmsg(16001, ����_����, Force(var0).����);
	trgmsg(16002, Force(var0).����, ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(2);
	trgscene().fade(255);
	trgscene().effect(17);
	trgmsg(16003, var1, Force(var0).����);
	trgmsg(16004, Force(var0).����, var1);
	trgmsg(16005, var1, Force(var0).����);
	trgscene().effect(20);
	trgmsg(16006, Force(var0).����, var1);
	trgscene().fade(0);
	trgscene().background(1);
	trgscene().fade(255);
	trgsound().playSfx(11);
	trgmsg(16007, Force(var0).����);
	trgscene().effect(21);
	trgmsg(16008, ����_����);
	trgmsg(16009, ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(-1);
	trgscene().fade(255);
	trgscene().eventStill(4);
	trgsound().playSfx(612);
	trgmsg(16010);
	trgscene().closeEventStill();

	Force(var0).setTitle(����_Ȳ��);
	Force(var0).setKokugou(��ȣ_��);

	List<City> cities(���üӼ�_����, var0);
	for (auto i = cities.begin(); i; i++)
	{
		i().addPublicOrder(20);
		if (i().���� != 0)
			i().addEnergy(20);
	}

	List<Person> officers(����Ӽ�_����, var0);
	officers.remove(Force(var0).����);
	officers.addLoyalty(20);

	List<Force> forces;
	forces.init();
	forces.remove(var0);
	forces.remove_all_but(���¼Ӽ�_�ܱ� + var0, -1);
	// forces.remove_all_but(176 + var0, 75, ������_��������);
	for (auto i = forces.begin(); i; i++)
	{
		if (i().���� == ����_Ȳ��)
			i().addRelations(var0, -50);
	}

	return true;
}

/** ��� õ�� */
bool PK_�����̺�Ʈ12(bool cond)
{
	if (cond)
	{
		if (Scenario().getStartDayCount() > daycount(190, 1, 1))
			return false;
		if (Person(����_��Ź).�ź� != �ź�_����)
			return false;
		if (Person(����_����).�ź� != �ź�_����)
			return false;
		if (Person(����_����).�ź� != �ź�_����)
			return false;
		int var0 = Person(����_��Ź).getForceId();
		if (daycount(190, 4, 1) > Scenario().getDayCount() && Building(�ǹ�_ȣ�ΰ�).getForceId() == var0)
			return false;
		if (Scenario().Ȳ�� == -1)
			return false;
		if (Person(Scenario().Ȳ��).�Ҽ� == �ǹ�_���)
			return false;
		if (!Force(var0).isProtectingTheEmperor())
			return false;
		if (City(����_����).getForceId() != var0)
			return false;
		if (City(����_���).getForceId() != var0)
			return false;
		if (Person(����_����).getForceId() != var0)
			return false;
		if (Person(����_��Ź).�Ҽ� != �ǹ�_����)
			return false;
		if (Force(Person(����_����).getForceId()).isEnemy(Person(����_����).getForceId()))
			return false;
		if (!Force(var0).isEnemy(Person(����_����).getForceId()))
			return false;
		if (!Force(var0).isEnemy(Person(����_����).getForceId()))
			return false;
		if (Force(var0).��ȣ��[Person(����_����).getForceId()] >= 40)
			return false;
		if (Force(var0).��ȣ��[Person(����_����).getForceId()] >= 40)
			return false;
		if (Person(����_��Ź).isCloseWith(����_����))
			return false;
		if (Person(����_��Ź).isCloseWith(����_����))
			return false;
		if (!Person(����_��Ź).isIdle())
			return false;
		if (!Person(����_����).isIdle())
			return false;
		return true;
	}

	int var0 = Person(����_��Ź).getForceId();
	int var1 = ����_����;
	if (Person(����_����).���� == ����_��Ź && Person(����_����).isIdle())
		var1 = ����_����;
	int var2 = ����_����;
	if (Person(����_����).���� == ����_��Ź && Person(����_����).isIdle())
		var2 = ����_����;

	trgmsg().setPerson(2, ����_��Ź);
	trgmsg().setCity(0, ����_����);
	trgmsg().setCity(1, ����_���);

	trgsound().playBgm(20);
	trgscene().move(Building(Person(����_��Ź).�Ҽ�), 1000);
	trgmsg(18282);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(1);
	trgscene().fade(255);
	trgmsg(18283, ����_��Ź, ����_����);
	trgscene().eventStill(21);
	trgmsg(18284, ����_����, ����_��Ź);
	trgmsg(18285, ����_��Ź, ����_����);
	trgmsg(18286, ����_����, ����_��Ź);
	trgsound().playSfx(11);
	trgmsg(18287, ����_��Ź, ����_����);
	trgscene().closeEventStill();
	trgscene().effect(13);
	trgmsg(18288, var1, ����_��Ź);
	if (Force(var0).isPlayer())
	{
		trgchooser().setItems(18290, 18291);
		if (trgchooser().show(18289, ����_��Ź) != 0)
		{
			trgmsg(18292, ����_��Ź, var1);
			return true;
		}
	}
	trgscene().effect(20);
	trgmsg(18293, ����_��Ź, var1);
	trgmsg(18294, var1, ����_��Ź);
	if (var2 == ����_����)
		trgmsg(18295, ����_��Ź, var2);
	else
		trgmsg(18296, ����_��Ź, var2);
	trgsound().playSfx(610);
	trgscene().eventStill(21);
	trgmsg(18297, var2, ����_��Ź);
	trgmsg(18298, ����_��Ź, var2);
	trgmsg(18299, var2, ����_��Ź);
	trgscene().closeEventStill();
	trgscene().fade(0);
	trgsleep(2000);
	trgscene().fade(255);
	trgmsg(18300, ����_��Ź, var2);
	trgmsg(18301, var2, ����_��Ź);
	trgmsg(18302, ����_��Ź, var2);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(-1);
	trgsound().playSfx(332);
	trgsound().playSfx(332);
	trgsound().playSfx(332);
	trgsound().playSfx(332);
	trgsound().playSfx(332);
	trgmsg(18303, Scenario().Ȳ��);
	trgmsg(18304, ����_��Ź);
	trgscene().fade(255);
	trgscene().eventStill(3);
	trgsound().playSfx(603);
	trgmsg(18305);
	trgscene().closeEventStill();

	Person(����_����).move(�ǹ�_���);
	Person(����_����).setLocationByBuildingId(�ǹ�_���);
	Person(����_����).move(�ǹ�_���);
	Person(����_����).setLocationByBuildingId(�ǹ�_���);
	Person(����_����).move(�ǹ�_���);
	Person(����_����).setLocationByBuildingId(�ǹ�_���);

	List<Person> officers;

	officers.init(����Ӽ�_����, var0);
	officers.remove_all_but(����Ӽ�_�Ҽ�, �ǹ�_����);
	officers.move(�ǹ�_���);
	officers.init(����Ӽ�_����, var0);
	officers.remove_all_but(����Ӽ�_�Ҽ�, �ǹ�_ȣ�ΰ�);
	officers.move(�ǹ�_���);
	officers.init(����Ӽ�_����, var0);
	officers.remove_all_but(����Ӽ�_�Ҽ�, �ǹ�_������);
	officers.move(�ǹ�_���);
	officers.init(����Ӽ�_����, var0);
	officers.remove_all_but(����Ӽ�_�Ҽ�, �ǹ�_������);
	officers.move(�ǹ�_���);

	officers.init(����Ӽ�_����, var0);
	officers.remove(Force(var0).����);
	for (auto i = officers.begin(); i; i++)
	{
		if (i().�ѽ� == �ѽ�_�߽�)
			i().addLoyalty(-10 - (2 * i().�Ǹ�));
	}

	List<Building> buildings;
	buildings.push_back(�ǹ�_����);
	buildings.push_back(�ǹ�_ȣ�ΰ�);
	buildings.push_back(�ǹ�_������);
	buildings.push_back(�ǹ�_������);
	buildings.remove_all_but(�ǹ��Ӽ�_����, var0);
	for (auto i = buildings.begin(); i; i++)
	{
		Building(�ǹ�_���).addGold(i().��);
		Building(�ǹ�_���).addFood(i().����);
		Building(�ǹ�_���).addTroops(i().����);
		Building(�ǹ�_���).addWeapons(����_â, i().����[����_â]);
		Building(�ǹ�_���).addWeapons(����_��, i().����[����_��]);
		Building(�ǹ�_���).addWeapons(����_��, i().����[����_��]);
		Building(�ǹ�_���).addWeapons(����_����, i().����[����_����]);
		Building(�ǹ�_���).addWeapons(����_����, i().����[����_����]);
		Building(�ǹ�_���).addWeapons(����_����, i().����[����_����]);
		Building(�ǹ�_���).addWeapons(����_����, i().����[����_����]);
		Building(�ǹ�_���).addWeapons(����_���, i().����[����_���]);
		Building(�ǹ�_���).addWeapons(����_����, i().����[����_����]);
		i().setGold(0);
		i().setFood(0);
		i().setHP(0);
		i().setTroops(0);
		i().setEnergy(0);
		i().setWeapons(����_â, 0);
		i().setWeapons(����_��, 0);
		i().setWeapons(����_��, 0);
		i().setWeapons(����_����, 0);
		i().setWeapons(����_����, 0);
		i().setWeapons(����_����, 0);
		i().setWeapons(����_����, 0);
		i().setWeapons(����_���, 0);
		i().setWeapons(����_����, 0);
	}

	City(����_����).setPublicOrder(0);
	City(����_����).resetWeapons();

	for (auto i = buildings.begin(); i; i++)
		i().neutralize();

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	/*
	trgmap().removeBuilding(71, 73);
	trgmap().removeBuilding(71, 74);
	trgmap().removeBuilding(72, 73);
	trgmap().removeBuilding(72, 74);
	trgmap().removeBuilding(72, 75);
	trgmap().removeBuilding(73, 72);
	trgmap().removeBuilding(73, 73);
	trgmap().removeBuilding(73, 74);
	trgmap().removeBuilding(74, 79);
	trgmap().removeBuilding(74, 80);
	trgmap().removeBuilding(75, 79);
	trgmap().removeBuilding(75, 80);
	trgmap().removeBuilding(76, 80);
	trgmap().removeBuilding(76, 81);
	trgmap().removeBuilding(83, 70);
	trgmap().removeBuilding(83, 71);
	trgmap().removeBuilding(84, 70);
	trgmap().removeBuilding(84, 71);
	trgmap().removeBuilding(84, 72);
	trgmap().removeBuilding(85, 70);
	trgmap().removeBuilding(85, 71);
	trgmap().removeBuilding(85, 72);
	*/

	City city(����_����);
	for (int i = 0; i < city.��������; i++)
	{
		Building building(city.������[i].building);
		if (isalive(building))
			trgmap().removeBuilding(building.getId());
	}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	Building(�ǹ�_���).addGold(30000);

	trgscene().fade(0);
	trgsleep();
	trgmap().refresh();
	trgscene().fade(255);

	return true;
}

/** �ݵ�Ź ���� �ر� */
bool PK_�����̺�Ʈ13(bool cond)
{
	if (cond)
	{
		if (Scenario().��ȣ != 1)
			return false;
		if (Person(����_��Ź).�ź� != �ź�_����)
			return false;
		if (Person(����_����).�ź� != �ź�_����)
			return false;
		if (Person(����_����).�ź� != �ź�_����)
			return false;
		int var0 = Person(����_��Ź).getForceId();
		if (daycount(191, 1, 1) > Scenario().getDayCount())
			return false;
		if (!Force(var0).isProtectingTheEmperor())
			return false;
		if (2 > Force(var0).���ü�)
			return false;
		if (Force(Person(����_����).getForceId()).isEnemy(Person(����_����).getForceId()))
			return false;
		if (!Force(var0).isEnemy(Person(����_����).getForceId()))
			return false;
		if (!Force(var0).isEnemy(Person(����_����).getForceId()))
			return false;
		if (Person(����_��Ź).isCloseWith(����_����))
			return false;
		if (Person(����_��Ź).isCloseWith(����_����))
			return false;
		if (!Person(����_��Ź).isIdle())
			return false;
		return true;
	}

	int var0 = Person(����_��Ź).getForceId();

	trgmsg().setPerson(2, ����_��Ź);

	trgsound().playBgm(16);
	trgscene().move(Building(Person(����_��Ź).�Ҽ�));
	trgmsg(18306);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(1);
	trgscene().fade(255);
	trgscene().effect(18);
	trgmsg(18307, ����_����, ����_��Ź);
	trgmsg(18308, ����_��Ź, ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(-1, 0);
	trgscene().fade(255);
	trgscene().eventStill(8);
	trgsound().playSfx(603);
	trgmsg(18309);
	trgscene().closeEventStill();

	List<Person> officers;
	officers.push_back(����_����);
	officers.push_back(����_����);
	officers.push_back(����_�հ�);
	officers.push_back(����_����);
	officers.push_back(����_����);
	officers.push_back(����_����);
	officers.push_back(����_������);
	officers.push_back(����_�Ѻ�);
	officers.push_back(����_����);
	officers.push_back(����_����);
	officers.push_back(����_����);
	officers.push_back(����_����);
	officers.push_back(����_���);
	officers.remove_all_but(����Ӽ�_�ź�, �ź�_����);
	for (auto i = officers.begin(); i; i++)
	{
		for (auto j = i; ++j; true)
			Force(i().getForceId()).addRelations(j().getForceId(), -40);
	}
	return true;
}

/** ���� ���� */
bool PK_�����̺�Ʈ14(bool cond)
{
	if (cond)
	{
		int var0 = Person(����_����).getForceId();
		if (Scenario().getDayCount() > daycount(194, 12, 1))
			return false;
		if (180 > Scenario().getElapsedDays())
			return false;
		if (City(����_����).getForceId() != var0)
			return false;
		if (City(����_����).getForceId() != var0)
			return false;
		if (Force(var0).���ü� > 4)
			return false;
		if (Force(Person(����_����).getForceId()).isPlayer())
			return false;
		if (City(����_�Ϻ�).getForceId() != Person(����_����).getForceId())
			return false;
		if (!Force(var0).isEnemy(Person(����_����).getForceId()))
			return false;
		if (Force(var0).��ȣ��[Person(����_����).getForceId()] > 61)
			return false;
		if (Person(����_����).isCloseWith(����_����))
			return false;
		if (!Person(����_����).isIdle())
			return false;
		return true;
	}

	int var0 = Person(����_����).getForceId();
	int var1 = ����_����;
	if (Person(����_���ĵ�).���� == ����_���� && Person(����_���ĵ�).isIdle())
		var1 = ����_���ĵ�;

	trgmsg().setPerson(2, ����_����);
	trgmsg().setPerson(3, ����_����);
	trgmsg().setCity(0, ����_����);
	trgmsg().setCity(1, ����_����);

	trgsound().playBgm(18);
	trgscene().move(Building(Person(����_����).�Ҽ�), 1200);
	trgmsg(18388);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(2);
	trgscene().fade(255);
	trgmsg(18389, ����_����, var1);
	trgmsg(18390, var1, ����_����);
	if (var1 == ����_���ĵ�)
		trgmsg(18391, ����_����, var1);
	else
		trgmsg(18392, ����_����, var1);
	trgmsg(18393, var1, ����_����);
	if (var1 == ����_���ĵ�)
		trgmsg(18394, ����_����, var1);
	else
		trgmsg(18395, ����_����, var1);
	trgscene().fade(0);
	trgsleep(2000);
	trgscene().background(2);
	trgscene().fade(255);
	trgsound().playBgm(21);
	trgscene().effect(18);
	trgmsg(18396, ����_����, ����_����);
	trgmsg(18397, ����_����, ����_����);
	trgmsg(18398, ����_����, ����_����);
	trgscene().effect(13);
	trgmsg(18399, ����_����, ����_����);
	trgscene().effect(20);
	trgmsg(18400, ����_����, ����_����);
	trgscene().eventStill(21);
	trgmsg(18401, ����_����, ����_����);
	trgmsg(18402, ����_����, ����_����);
	trgscene().closeEventStill();
	trgscene().fade(0);
	trgsleep();
	trgscene().background(-1);
	trgscene().fade(255);
	trgscene().eventStill(8);
	trgsound().playSfx(603);
	trgmsg(18403);
	trgscene().closeEventStill();

	Force(var0).setRelations(Person(����_����).getForceId(), 0);
	Force(var0).unally(Person(����_����).getForceId());

	Person(����_����).resetRelationship(����_����);

	List<Building> buildings(�ǹ��Ӽ�_����, var0);
	for (auto i = buildings.begin(); i; i++)
	{
		if (i().���� != 0)
			i().addEnergy(10);
	}

	List<Unit> units(�δ�Ӽ�_����, var0);
	for (auto i = units.begin(); i; i++)
	{
		if (i().���� != 0)
			i().addEnergy(10);
	}

	if (Person(����_�尳).getForceId() == Person(����_����).getForceId() && Person(����_�尳).�ź� == �ź�_�Ϲ� && Person(����_�尳).isIdle())
		Person(����_�尳).banish();

	return true;
}

/*
bool PK_�����̺�Ʈ15(bool cond)
{
}

bool PK_�����̺�Ʈ16(bool cond)
{
}

bool PK_�����̺�Ʈ17(bool cond)
{
}

bool PK_�����̺�Ʈ18(bool cond)
{
}

bool PK_�����̺�Ʈ19(bool cond)
{
}

bool PK_�����̺�Ʈ20(bool cond)
{
}

bool PK_�����̺�Ʈ21(bool cond)
{
}
*/

/** �������� */
bool PK_�����̺�Ʈ22(bool cond)
{
	if (cond)
	{
		int force_id = trgevent().getPerson().getForceId();
		if (Person(����_����).getForceId() != force_id)
			return false;
		if (Person(����_����).getForceId() != force_id)
			return false;
		if (Person(����_���).getForceId() != force_id)
			return false;
		if (Scenario().��ȣ != 0)
			return false;
		if (Scenario().getElapsedDays() != 0)
			return false;
		if (!Person(����_����).isIdle())
			return false;
		if (!Person(����_����).isIdle())
			return false;
		if (!Person(����_���).isIdle())
			return false;
		return true;
	}

	int var0;

	trgmsg().setPerson(2, ����_����);
	trgmsg().setCity(0, ����_��);

	trgsound().playBgm(18);
	trgscene().move(Building(Person(����_����).�Ҽ�), 1500);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(4);
	trgscene().fade(255);
	var0 = trgsound().playSfxLoop(615);
	trgmsg(15115);
	trgmsg(15116, ����_����, ����_���);
	trgscene().effect(13);
	trgmsg(15117, ����_���, ����_����, 15093);
	trgmsg(15118, ����_����, ����_���);
	trgsound().playSfx(610);
	trgmsg(15119, ����_���, ����_����);
	trgmsg(15120, ����_����, ����_���);
	trgmsg(15121, ����_���, ����_����);
	trgmsg(15122, ����_����, ����_���);
	trgscene().fade(0);
	trgsleep(2000);
	trgscene().fade(255);
	trgmsg(15123, ����_���, ����_����);
	trgscene().effect(18);
	trgmsg(15124, ����_����, ����_����, 15093);
	trgmsg(15125, ����_���, ����_����);
	trgmsg(15126, ����_����, ����_���, 15093);
	trgmsg(15127, ����_����, ����_����);
	trgscene().effect(20);
	trgmsg(15128, ����_����, ����_���);
	trgmsg(15129, ����_���, ����_����);
	trgsound().stopSfxLoop(var0);
	trgscene().fade(0);
	trgsound().playBgm(17);
	trgsleep(2000);
	var0 = trgsound().playSfxLoop(608);
	trgscene().background(0);
	trgscene().fade(255);
	trgmsg(15130, ����_����, ����_����);
	trgsound().playSfx(606);
	trgsleep(1200);
	trgmsg(15131, ����_����, ����_���);
	trgsound().playSfx(606);
	trgsleep(1200);
	trgmsg(15132, ����_���, ����_����);
	trgsound().playSfx(606);
	trgsound().stopSfxLoop(var0);
	trgsleep(1200);
	trgscene().effect(0);
	trgmsg(15133);

	return true;
}

/*
bool PK_�����̺�Ʈ23(bool cond)
{
}

bool PK_�����̺�Ʈ24(bool cond)
{
}

bool PK_�����̺�Ʈ25(bool cond)
{
}

bool PK_�����̺�Ʈ26(bool cond)
{
}

bool PK_�����̺�Ʈ27(bool cond)
{
}

bool PK_�����̺�Ʈ28(bool cond)
{
}

bool PK_�����̺�Ʈ29(bool cond)
{
}

bool PK_�����̺�Ʈ30(bool cond)
{
}

bool PK_�����̺�Ʈ31(bool cond)
{
}

bool PK_�����̺�Ʈ32(bool cond)
{
}

bool PK_�����̺�Ʈ33(bool cond)
{
}

bool PK_�����̺�Ʈ34(bool cond)
{
}

bool PK_�����̺�Ʈ35(bool cond)
{
}

bool PK_�����̺�Ʈ36(bool cond)
{
}

bool PK_�����̺�Ʈ37(bool cond)
{
}

bool PK_�����̺�Ʈ38(bool cond)
{
}

bool PK_�����̺�Ʈ39(bool cond)
{
}

bool PK_�����̺�Ʈ40(bool cond)
{
}

bool PK_�����̺�Ʈ41(bool cond)
{
}

bool PK_�����̺�Ʈ42(bool cond)
{
}

bool PK_�����̺�Ʈ43(bool cond)
{
}

bool PK_�����̺�Ʈ44(bool cond)
{
}

bool PK_�����̺�Ʈ45(bool cond)
{
}

bool PK_�����̺�Ʈ46(bool cond)
{
}

bool PK_�����̺�Ʈ47(bool cond)
{
}

bool PK_�����̺�Ʈ48(bool cond)
{
}

bool PK_�����̺�Ʈ49(bool cond)
{
}

bool PK_�����̺�Ʈ50(bool cond)
{
}

bool PK_�����̺�Ʈ63(bool cond)
{
}

bool PK_�����̺�Ʈ64(bool cond)
{
}

bool PK_�����̺�Ʈ65(bool cond)
{
}

bool PK_�����̺�Ʈ66(bool cond)
{
}

bool PK_�����̺�Ʈ67(bool cond)
{
}

bool PK_�����̺�Ʈ68(bool cond)
{
}

bool PK_�����̺�Ʈ69(bool cond)
{
}

bool PK_�����̺�Ʈ70(bool cond)
{
}

bool PK_�����̺�Ʈ71(bool cond)
{
}

bool PK_�����̺�Ʈ72(bool cond)
{
}

bool PK_�����̺�Ʈ73(bool cond)
{
}

bool PK_�����̺�Ʈ74(bool cond)
{
}

bool PK_�����̺�Ʈ75(bool cond)
{
}

bool PK_�����̺�Ʈ78(bool cond)
{
}

bool PK_�����̺�Ʈ79(bool cond)
{
}

bool PK_�����̺�Ʈ80(bool cond)
{
}

bool PK_�����̺�Ʈ85(bool cond)
{
}

bool PK_�����̺�Ʈ86(bool cond)
{
}
*/