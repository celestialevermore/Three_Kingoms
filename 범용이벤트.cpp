/** ��ȣ���屺 */
bool PK_�����̺�Ʈ52(bool cond)
{
	if (cond)
	{
		if (180 > Scenario().getElapsedDays())
			return false;
		int month = Scenario().��;
		if (month != 1 && month != 4 && month != 7 && month != 12)
			return false;
		if (!trgevent().getPerson().isIdle())
			return false;
		if (Force(trgevent().getPerson().getForceId()).���� == -1)
			return false;
		if (!Person(Force(trgevent().getPerson().getForceId()).����).isIdle())
			return false;
		if (Force(trgevent().getPerson().getForceId()).���� > ����_��)
			return false;
		if (10 > Force(trgevent().getPerson().getForceId()).���ü�)
			return false;
		trglist<Person>()(0).init(����Ӽ�_����, trgevent().getPerson().getForceId(), ������_����);
		trglist<Person>()(0).remove(trgevent().getPerson());
		trglist<Person>()(0).remove(Force(trgevent().getPerson().getForceId()).����);
		trglist<Person>()(0).remove_all_but(����Ӽ�_�ɷ� + ����ɷ�_����, 90, ������_ũ�ų�����);
		trglist<Person>()(0).remove_all_but(����Ӽ�_����, 20000, ������_ũ�ų�����);
		trglist<Person>()(0).remove_all_but(����Ӽ�_�漺��, 100, ������_ũ�ų�����);
		if (5 > trglist<Person>()(0).size())
			return false;
		return true;
	}

	trglist<Person>()(0).sort(����Ӽ�_����, ����_��������);

	trgmsg().setPerson(2, trgevent().getPerson());
	trgmsg().setPerson(3, Force(trgevent().getPerson().getForceId()).����);
	trgsound().playBgm(17);
	trgscene().move(Building(trgevent().getPerson().�Ҽ�));
	trgsound().playSfx(601);
	trgmsg(16030, ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(2);
	trgscene().fade(255);
	trgmsg(16031, trgevent().getPerson(), Force(trgevent().getPerson().getForceId()).����);
	trgscene().effect(16);
	trgmsg(16032, Force(trgevent().getPerson().getForceId()).����, trgevent().getPerson());
	trgsound().playSfx(11);
	trgmsg(16033, trgevent().getPerson(), Force(trgevent().getPerson().getForceId()).����);
	trgscene().effect(14);
	trgmsg(16034, Force(trgevent().getPerson().getForceId()).����, trgevent().getPerson());
	trglist<Person>()(0).select(trglist<Person>()(0), 5, 5, 16035, false);
	trgmsg().setPerson(2, trglist<Person>()(0)[0]);
	trgmsg().setPerson(3, trglist<Person>()(0)[1]);
	trgmsg().setPerson(4, trglist<Person>()(0)[2]);
	trgmsg().setPerson(5, trglist<Person>()(0)[3]);
	trgmsg().setPerson(6, trglist<Person>()(0)[4]);
	trgmsg(16036, Force(trgevent().getPerson().getForceId()).����, trgevent().getPerson());
	trgmsg(16037, trgevent().getPerson(), Force(trgevent().getPerson().getForceId()).����);
	trgmsg(16038, Force(trgevent().getPerson().getForceId()).����, trgevent().getPerson());
	trgscene().fade(0);
	trgsleep();
	trgscene().background(1);
	trgscene().fade(255);
	trgscene().effect(11);
	trgmsg(16039, trgevent().getPerson());
	for (auto i = trglist<Person>()(0).begin(); i; i++)
	{
		if (i().isIdle() && i().�Ҽ� == trgevent().getPerson().�Ҽ�)
			trgmsg(16040, i());
	}
	trgscene().effect(21);
	trgmsg(16041);
	trgsound().playSfx(612);
	trgmsg(16042);

	for (auto i = trglist<Person>()(0).begin(); i; i++)
	{
		if (i().�漺�� < 150)
			i().setLoyalty(150);
		i().addKouseki(2000);
		i().addWeaponExp(����_â, 50);
		i().addWeaponExp(����_��, 50);
		i().addWeaponExp(����_��, 50);
		i().addWeaponExp(����_����, 50);
		i().addStatExp(����ɷ�_���, 50);
		i().addStatExp(����ɷ�_����, 50);
	}

	return true;
}

/** ���� */
bool PK_�����̺�Ʈ53(bool cond)
{
	if (cond)
	{
		if (!trgevent().getPerson().isIdle())
			return false;
		if (360 > Scenario().getElapsedDays())
			return false;
		int force_id = trgevent().getPerson().getForceId();
		if (City(����_��).getForceId() != force_id)
			return false;
		if (trgevent().getPerson().�Ҽ� != �ǹ�_��)
			return false;
		if (Force(force_id).���� > ����_���屺)
			return false;
		if (10 > Force(force_id).���ü�)
			return false;
		if (Item(����_����).���� != ��������_�̵���)
			return false;
		return true;
	}

	trgmsg().setCity(0, ����_��);
	trgsound().playBgm(17);
	trgscene().move(Building(trgevent().getPerson().�Ҽ�), 1200);
	trgsound().playSfx(601, 100);
	trgmsg(16043, ����_����, trgevent().getPerson());
	trgmsg(16044, trgevent().getPerson());
	trgscene().fade(0);
	trgsleep(1000);
	trgscene().background(4);
	trgscene().fade(255);
	int var0 = trgsound().playSfxLoop(615);
	trgmsg(16045, trgevent().getPerson());
	trgmsg(16046, ����_����);
	trgscene().fade(0);
	trgsleep(1000);
	trgscene().fade(255);
	trgscene().effect(18);
	trgmsg(16047, ����_����);
	trgmsg(16048, trgevent().getPerson());
	trgmsg(16049, ����_����);
	trgsound().playSfx(11, 100);
	trgmsg(16050, trgevent().getPerson());
	trgmsg().setItem(0, ����_����);
	trgmsg(16051, ����_����);
	trgsound().stopSfxLoop(var0);
	trgsound().playSfx(612, 100);
	trgmsg(16052, trgevent().getPerson());

	Item(����_����).���� = ��������_����;
	Item(����_����).�������� = trgevent().getPerson().getId();

	return true;
}

/** ���� ���� */
bool PK_�����̺�Ʈ54(bool cond)
{
	if (cond)
	{
		if (!trgevent().getPerson().isIdle())
			return false;

		if (!randbool(5))
			return false;

		if (180 > Scenario().getElapsedDays())
			return false;

		trglist<Person>()(0).init(����Ӽ�_����, trgevent().getPerson().getForceId());
		trglist<Person>()(0).remove_all_but(����Ӽ�_�Ҽ�, trgevent().getPerson().�Ҽ�);
		trglist<Person>()(0).remove(trgevent().getPerson());
		trglist<Person>()(0).remove_all_but(����Ӽ�_�漺��, 90, ������_ũ�ų�����);
		trglist<Person>()(0).remove_all_but(����Ӽ�_�ɷ� + ����ɷ�_��ġ, 80, ������_ũ�ų�����);
		trglist<Person>()(0).remove_all_but(����Ӽ�_����, true);
		if (trglist<Person>()(0).size() <= 0)
			return false;

		trglist<Person>()(1).clear();
		trglist<Person>()(2).init(����Ӽ�_���, true);
		trglist<Person>()(2).remove_all_but(����Ӽ�_����, true);
		trglist<Person>()(2).remove_all_but(����Ӽ�_ģ��, false, trgevent().getPerson().getId());
		trglist<Person>()(2).remove_all_but(����Ӽ�_�����, -1);
		trglist<Person>()(2).remove_all_but(����Ӽ�_������, -1);

		for (auto i = trglist<Person>()(2).begin(); i; i++)
		{
			if (i().���� >= i().���� && i().���� >= i().��ġ)
				continue;

			for (auto j = trglist<Person>()(0).begin(); j; j++)
			{
				if (j().isGikyoudai(i().getId()) || j().��� == i().��� || j().���� == i().���� || j().isLike(i().getId()))
				{
					trglist<Person>()(1).push_back(i());
					break;
				}
			}
		}

		return 0 < trglist<Person>()(1).size();
	}

	Person var0 = trglist<Person>()(1).random();
	Person var1 = trglist<Person>()(0).random();

	trglist<Person>()(2).clear();

	for (auto i = trglist<Person>()(0).begin(); i; i++)
	{
		if (i().isGikyoudai(var0.getId()) || i().��� == var0.��� || i().���� == var0.���� || i().isLike(var0.getId()) || var0.isLike(i().getId()))
			trglist<Person>()(2).push_back(var1);
	}

	if (0 >= trglist<Person>()(2).size())
		assert(false);
	else
		var1 = trglist<Person>()(2).random();

	trgmsg().setPerson(2, trgevent().getPerson());
	trgmsg().setPerson(3, var1);
	trgsound().playBgm(18);
	trgscene().move(Building(trgevent().getPerson().�Ҽ�));
	trgsound().playSfx(601);
	trgmsg(16053, ����_����);
	trgmsg(16054, trgevent().getPerson());
	trgscene().fade(0);
	trgsleep();
	trgscene().background(2);
	trgscene().fade(255);
	trgmsg().setPerson(2, var0);
	trgmsg().setPerson(3, var1);
	trgmsg().setPerson(4, trgevent().getPerson());
	trgmsg(16055, trgevent().getPerson(), var1);
	trgmsg(16056, var1, trgevent().getPerson());
	trgchooser().setItems(16057, 16058);
	if (trgchooser().show(16059, trgevent().getPerson(), var1) != 0)
	{
		trgmsg(16061, trgevent().getPerson(), var1);
		return true;
	}
	trgmsg(16060, trgevent().getPerson(), var1);
	trgmsg(16062, var1, trgevent().getPerson());
	trgscene().fade(0);
	trgsleep();
	trgscene().background(5);
	trgscene().fade(255);
	int var3 = trgsound().playSfxLoop(614);
	trgmsg().setPerson(2, trgevent().getPerson());
	trgmsg(16063, var1, var0);
	trgscene().eventStill(23);
	trgmsg(16064, var0, var1);
	trgmsg(16065, var1, var0);
	trgscene().closeEventStill();
	trgscene().effect(17);
	trgmsg(16066, var0, var1);
	trgsound().stopSfxLoop(var3);

	trgdebate().init();
	trgdebate().setSlot(0, var1, true);
	trgdebate().setSlot(1, var0, false);
	trgdebate().run();
	bool var4 = trgdebate().getWinner() == 0;

	if (var4)
	{
		trgscene().fade(0);
		trgsleep();
		trgscene().background(5);
		trgscene().fade(255);
		trgsound().playSfx(11);
		trgmsg(16067, var0, var1);
		trgscene().fade(0);
		trgsleep();
		trgscene().background(2);
		trgscene().fade(255);
		trgmsg().setPerson(2, var0);
		trgmsg().setPerson(3, var1);
		trgmsg().setPerson(4, trgevent().getPerson());
		trgmsg(16068, var1, trgevent().getPerson());
		trgmsg(16069, var0, trgevent().getPerson());
		trgmsg(16070, trgevent().getPerson(), var0);
		trgmsg(16071, var0, trgevent().getPerson());
		trgmsg().setPerson(0, var0);
		trgsound().playSfx(612);
		trgmsg(16072);
	}
	else
	{
		trgscene().fade(0);
		trgsleep();
		trgscene().background(5);
		trgscene().fade(255);
		trgmsg(16073, var0, var1);
		trgsound().playSfx(613, 100);
		trgmsg(16074, var1, var0);
		trgscene().fade(0);
		trgsleep();
		trgscene().background(2);
		trgscene().fade(255);
		trgsound().playSfx(12);
		trgmsg(16075, var1, trgevent().getPerson());
	}

	if (var4)
	{
		var1.addKouseki(200);
		var0.setLocation(trgevent().getPerson().�Ҽ�);
		var0.changeForce(trgevent().getPerson().getForceId(), var1, 0);
		var0.addKouseki(200);
		var0.setLoyalty(var1.�漺��);
	}
	else
	{
		trglist<City>()(0).init();
		trglist<City>()(0).remove(trgevent().getPerson().�Ҽӵ���);
		City var5 = trglist<City>()(0).random();
		var0.appear();
		var0.move(var5.toBuilding());
		var0.setBannedKunshu(trgevent().getPerson().getId(), 12);
	}
	return true;
}

/** ���� ���� */
bool PK_�����̺�Ʈ55(bool cond)
{
	if (cond)
	{
		if (!trgevent().getPerson().isIdle())
			return false;

		if (!randbool(5))
			return false;

		if (180 > Scenario().getElapsedDays())
			return false;

		trglist<Person>()(0).init(����Ӽ�_����, trgevent().getPerson().getForceId());
		trglist<Person>()(0).remove_all_but(����Ӽ�_�Ҽ�, trgevent().getPerson().�Ҽ�);
		trglist<Person>()(0).remove(trgevent().getPerson());
		trglist<Person>()(0).remove_all_but(����Ӽ�_�漺��, 90, ������_ũ�ų�����);
		trglist<Person>()(0).remove_all_but(����Ӽ�_�ɷ� + ����ɷ�_����, 75, ������_ũ�ų�����);
		trglist<Person>()(0).remove_all_but(����Ӽ�_����, true);
		if (trglist<Person>()(0).size() <= 0)
			return false;

		trglist<Person>()(1).clear();
		trglist<Person>()(2).init(����Ӽ�_���, true);
		trglist<Person>()(2).remove_all_but(����Ӽ�_�ɷ� + ����ɷ�_����, 70, ������_ũ�ų�����);
		trglist<Person>()(2).remove_all_but(����Ӽ�_����, true);
		trglist<Person>()(2).remove_all_but(����Ӽ�_ģ��, false, trgevent().getPerson().getId());
		trglist<Person>()(2).remove_all_but(����Ӽ�_�����, -1);
		trglist<Person>()(2).remove_all_but(����Ӽ�_������, -1);

		for (auto i = trglist<Person>()(2).begin(); i; i++)
		{
			for (auto j = trglist<Person>()(0).begin(); j; j++)
			{
				if (j().isCloseWith(i().getId()) || j().isDislike(i().getId()) || i().isDislike(j().getId()) || j().���� == i().����)
					continue;

				if (j().��� == i().��� || j().isLike(i().getId()))
				{
					trglist<Person>()(1).push_back(i());
					break;
				}
			}
		}

		return 0 < trglist<Person>()(1).size();
	}

	Person var0 = trglist<Person>()(1).random();
	Person var1 = trglist<Person>()(0).random();

	trgmsg().setPerson(2, trgevent().getPerson());
	trgmsg().setPerson(3, var1);
	trgmsg().setPerson(4, var0);
	trgsound().playBgm(18);
	trgscene().move(Building(trgevent().getPerson().�Ҽ�));
	trgsound().playSfx(600);
	trgmsg(16076, ����_����);
	trgmsg(16077, trgevent().getPerson());
	trgscene().fade(0);
	trgsleep();
	trgscene().background(2);
	trgscene().fade(255);
	trgmsg(16078, trgevent().getPerson(), var1);
	trgmsg(16079, var1, trgevent().getPerson());
	trgchooser().setItems(16080, 16081);
	if (trgchooser().show(16082, trgevent().getPerson(), var1) != 0)
	{
		trgmsg(16084, trgevent().getPerson(), var1);
		return true;
	}
	trgmsg(16085, var1, trgevent().getPerson());
	trgscene().fade(0);
	trgsleep();
	trgscene().background(4);
	trgscene().fade(255);
	int var3 = trgsound().playSfxLoop(615);
	trgmsg(16086, var1, var0);
	trgscene().eventStill(25);
	trgmsg(16087, var0, var1);
	trgmsg(16088, var1, var0);
	trgmsg(16089, var0, var1);
	trgmsg(16090, var1, var0);
	trgscene().closeEventStill();
	trgscene().effect(17);
	trgmsg(16091, var0, var1);
	trgsound().stopSfxLoop(var3);

	trgduel().init();
	trgduel().setSlot(0, 0, var1);
	trgduel().setSlot(1, 0, var0);
	trgduel().setControl(0, 0);
	trgduel().run(1);
	bool var4 = trgduel().getWinner() == 0;

	if (var4)
	{
		trgscene().fade(0);
		trgsleep();
		trgscene().background(4);
		trgscene().fade(255);
		int var5 = trgsound().playSfxLoop(615);
		trgsound().playSfx(11);
		trgmsg(16092, var0, var1);
		trgsound().stopSfxLoop(var5);
		trgscene().fade(0);
		trgsleep();
		trgscene().background(2);
		trgscene().fade(255);
		trgmsg(16093, var1, trgevent().getPerson());
		trgmsg(16094, var0, trgevent().getPerson());
		trgmsg(16095, trgevent().getPerson(), var0);
		trgmsg(16096, var0, trgevent().getPerson());
		trgmsg().setPerson(0, var0);
		trgsound().playSfx(612);
		trgmsg(16097);
	}
	else
	{
		trgscene().fade(0);
		trgsleep();
		trgscene().background(4);
		trgscene().fade(255);
		int var5 = trgsound().playSfxLoop(615);
		trgmsg(16098, var0, var1);
		trgsound().playSfx(613);
		trgmsg(16099, var1, var0);
		trgsound().stopSfxLoop(var5);
		trgscene().fade(0);
		trgsleep();
		trgscene().background(2);
		trgscene().fade(255);
		trgsound().playSfx(12);
		trgmsg(16100, var1, trgevent().getPerson());
	}

	if (var4)
	{
		var1.addKouseki(200);
		var0.setLocation(trgevent().getPerson().�Ҽ�);
		var0.changeForce(trgevent().getPerson().getForceId(), var1, 0);
		var0.addKouseki(200);
		var0.setLoyalty(var1.�漺��);
	}
	else
	{
		trglist<City>()(0).init();
		trglist<City>()(0).remove(trgevent().getPerson().�Ҽӵ���);
		City var5 = trglist<City>()(0).random();
		var0.appear();
		var0.move(var5.toBuilding());
		var0.setBannedKunshu(trgevent().getPerson().getId(), 12);
	}
	return true;
}

/** ��籸�� */
bool PK_�����̺�Ʈ56(bool cond)
{
	if (cond)
	{
		int month = Scenario().��;
		if (month != 1 && month != 4 && month != 7 && month != 10)
			return false;
		if (!trgevent().getPerson().isIdle())
			return false;
		if (Force(trgevent().getPerson().getForceId()).���� >= ����_��)
			return false;
		if (35 > Force(trgevent().getPerson().getForceId()).���ü�)
			return false;
		if (360 > Scenario().getElapsedDays())
			return false;
		trglist<District>()(0).init(���ܼӼ�_����, trgevent().getPerson().getForceId());
		trglist<District>()(0).remove(Force(trgevent().getPerson().getForceId()).getFirstDistrictId());
		if (trglist<District>()(0).size() <= 0)
			return false;
		trglist<Person>()(0).init(����Ӽ�_����, trgevent().getPerson().getForceId());
		trglist<Person>()(0).remove(trgevent().getPerson());
		trglist<Person>()(0).remove_all_but(����Ӽ�_����, true);
		trglist<Person>()(0).remove_all_but(����Ӽ�_ģ��, false, trgevent().getPerson().getId());
		trglist<Person>()(0).remove_all_but(����Ӽ�_�Ҽ�, trgevent().getPerson().�Ҽ�);
		trglist<Person>()(0).remove_all_but(����Ӽ�_�Ǹ�, �Ǹ�_����, ������_�۰ų�����);
		trglist<Person>()(1).clear();
		for (auto i = trglist<District>()(0).begin(); i; i++)
		{
			Person totoku(i().����);
			if (totoku.isCloseWith(trgevent().getPerson()) && totoku.�漺�� >= 100 && totoku.isIdle())
			{
				trglist<Person>()(1).push_back(totoku);
				trglist<Person>()(0).remove_all_but(����Ӽ�_ģ��, false, totoku.getId());
			}
		}
		return trglist<Person>()(1).size() > 0 && trglist<Person>()(0).size() > 0;
	}

	Person var0 = trglist<Person>()(1).random();
	Person var1 = trglist<Person>()(0).random();
	int var2 = 1000;

	// �ŷ�, ������ ���� ���� ����
	for (auto i = trglist<Person>()(0).begin(); i; i++)
	{
		if (i().�ŷ� < var2)
		{
			var2 = i().�ŷ�;
			var1 = i();
		}
		else if (i().�ŷ� == var2 && i().���� < var1.����)
		{
			var1 = i();
		}
	}

	trgmsg().setPerson(2, trgevent().getPerson());
	trgmsg().setPerson(3, var1);
	trgsound().playBgm(20);
	trgscene().move(Building(trgevent().getPerson().�Ҽ�), 800);
	trgsound().playSfx(601);
	trgmsg(16101, ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(2);
	trgscene().fade(255);
	trgmsg().setPerson(2, var0);
	trgmsg().setPerson(4, trgevent().getPerson());
	trgmsg(16102, trgevent().getPerson(), var1);
	trgscene().effect(16);
	trgmsg(16103, var1, trgevent().getPerson());
	trgmsg(16104, trgevent().getPerson(), var1);
	trgsound().playSfx(616);
	trgmsg(16105, var1, trgevent().getPerson());
	trgsound().playSfx(12);
	trgmsg(16106, trgevent().getPerson(), var1);
	trgsound().playSfx(616);
	trgmsg(16107, var1, trgevent().getPerson());
	trgchooser().setItems(16108, 16109);
	int var3 = trgchooser().show(16110, trgevent().getPerson());

	if (var3 == 0)
	{
		trgscene().effect(20);
		trgmsg(16111, trgevent().getPerson(), var1);
		trgmsg(16112, var1, trgevent().getPerson());
		trgmsg(16113, trgevent().getPerson(), var1);
		trgsound().playSfx(613);
		trgmsg(16114, var1, trgevent().getPerson());
	}
	else
	{
		trgscene().effect(20);
		trgmsg(16115, trgevent().getPerson(), var1);
		trgmsg(16116, var1, trgevent().getPerson());
		trgscene().fade(0);
		trgsleep(2000);
		trgscene().background(-1);
		trgscene().fade(255);
		trgscene().eventStill(8);
		trgsound().playSfx(12);
		trgmsg(16117);
		trgscene().closeEventStill();
	}

	if (var3 == 0)
	{
		var1.addLoyalty(-20);
	}
	else
	{
		trgevent().getPerson().resetRelationship(var0);
		var0.newForce();
		trglist<Person>()(0).init(����Ӽ�_����, trgevent().getPerson().getForceId());
		trglist<Person>()(0).remove(trgevent().getPerson());
		trglist<Person>()(0).addLoyalty(-5);
		trglist<City>()(0).init(���üӼ�_����, trgevent().getPerson().getForceId());
		trglist<City>()(0).addPublicOrder(-10);
	}

	return true;
}

/** ��Ź */
bool PK_�����̺�Ʈ76(bool cond)
{
	if (cond)
	{
		if (trgmgr().getElapsedDays(114) <= 90 && 1 <= trgmgr().getElapsedDays(114))
			return false;
		if (!trgevent().getPerson().isIdle())
			return false;
		if (!randbool(5))
			return false;
		if (360 > Scenario().getElapsedDays())
			return false;
		int month = Scenario().��;
		if (month != 2 && month != 6 && month != 10)
			return false;
		if (Force(trgevent().getPerson().getForceId()).���� >= ����_�ָ�)
			return false;
		if (5 > Force(trgevent().getPerson().getForceId()).���ü�)
			return false;
		trglist<Person>()(0).init(����Ӽ�_����, trgevent().getPerson().getForceId());
		trglist<Person>()(0).remove(trgevent().getPerson());
		if (trglist<Person>()(0).size() < 20)
			return false;
		trglist<Person>()(1).clear();
		trglist<Person>()(0).init(����Ӽ�_����, trgevent().getPerson().getForceId());
		trglist<Person>()(0).remove(trgevent().getPerson());
		trglist<Person>()(0).remove_all_but(����Ӽ�_����, true);
		trglist<Person>()(0).remove_all_but(����Ӽ�_�Ǹ�, �Ǹ�_����, ������_ũ�ų�����);
		trglist<Person>()(0).remove_all_but(����Ӽ�_�漺��, 100, ������_ũ�ų�����);
		trglist<Person>()(0).remove_all_but(����Ӽ�_����, 10000, ������_ũ�ų�����);
		for (auto i = trglist<Person>()(0).begin(); i; i++)
		{
			if (i().isDislike(trgevent().getPerson().getId()) || trgevent().getPerson().isDislike(i().getId()))
				continue;
			trglist<Person>()(1).push_back(i());
		}
		if (trglist<Person>()(1).size() <= 0)
			return false;
		trglist<Person>()(2).clear();
		trglist<Person>()(3).clear();
		trglist<Person>()(0).init(����Ӽ�_����, trgevent().getPerson().getForceId());
		trglist<Person>()(0).remove(trgevent().getPerson());
		trglist<Person>()(0).remove_all_but(����Ӽ�_����, true);
		trglist<Person>()(0).remove_all_but(����Ӽ�_�Ǹ�, �Ǹ�_����, ������_ũ�ų�����);
		trglist<Person>()(0).remove_all_but(����Ӽ�_�漺��, 95, ������_ũ�ų�����);
		trglist<Person>()(0).remove_all_but(����Ӽ�_����, 2000, ������_��������);
		trglist<Person>()(0).remove_all_but(����Ӽ�_�ź�, �ź�_�Ϲ�);
		for (auto i = trglist<Person>()(0).begin(); i; i++)
		{
			if (i().isDislike(trgevent().getPerson().getId()) || trgevent().getPerson().isDislike(i().getId()))
				continue;
			if (70 <= i().��� || 70 <= i().���� || 70 <= i().���� || 70 <= i().��ġ || 70 <= i().�ŷ�)
				trglist<Person>()(2).push_back(i());
		}
		for (auto i = trglist<Person>()(2).begin(); i; i++)
		{
			for (auto j = trglist<Person>()(1).begin(); j; j++)
			{
				if (j().isCloseWith(i().getId()) || j().isDislike(i().getId()) || i().isDislike(j().getId()))
					continue;
				trglist<Person>()(3).push_back(i());
			}
		}
		return 0 < trglist<Person>()(3).size();
	}

	Person var0 = trglist<Person>()(1).random();
	trglist<Person>()(3).sort(����Ӽ�_����, ����_��������);
	Person var1 = trglist<Person>()(3).random();

	for (auto i = trglist<Person>()(3).begin(); i; i++)
	{
		if (var0.isLike(i().getId()) || var0.��� == i().���)
		{
			var1 = i();
			break;
		}
	}

	trgmsg().setPerson(2, trgevent().getPerson());
	trgmsg().setPerson(3, var0);
	trgmsg().setPerson(4, var1);
	trgsound().playBgm(18);
	trgscene().move(Building(trgevent().getPerson().�Ҽ�));
	trgscene().fade(0);
	trgsleep();
	trgscene().background(2);
	trgscene().fade(255);
	trgmsg(18734, trgevent().getPerson());
	trgsound().playSfx(610);
	trgmsg(18735, var0, trgevent().getPerson());
	trgmsg(18736, trgevent().getPerson(), var0);
	trgmsg(18737, var0, trgevent().getPerson());
	trgmsg(18738, trgevent().getPerson(), var0);
	trgmsg(18739, trgevent().getPerson());
	trgscene().fade(0);
	trgsleep();
	trgscene().eventStill(21);
	trgscene().fade(255);
	trgmsg(18740, var1, trgevent().getPerson());
	trgsound().playSfx(610);
	trgmsg(18741, trgevent().getPerson(), var1);
	trgmsg(18742, var1, trgevent().getPerson());
	trgmsg(18743, trgevent().getPerson(), var1);
	trgmsg(18744, var1, trgevent().getPerson());
	trgmsg(18745, trgevent().getPerson(), var1);
	trgscene().closeEventStill();
	trgscene().effect(20);
	trgmsg(18746, var1, trgevent().getPerson());
	trgscene().fade(0);
	trgsleep();
	trgscene().background(-1);
	trgsound().playSfx(11);
	trgmsg(18747);
	trgscene().fade(255);

	trgmgr().setLastRunTime(114, Scenario().getDayCount());

	var0.addKouseki(200);
	var1.addKouseki(2000);
	var1.addLoyalty(2 + (2 * var1.�Ǹ�));

	return true;
}

/** �߻�� */
bool PK_�����̺�Ʈ77(bool cond)
{
	if (cond)
	{
		if (!trgevent().getPerson().isIdle())
			return false;

		if (!randbool(5))
			return false;

		if (360 > Scenario().getElapsedDays())
			return false;

		int month = Scenario().��;
		if (month != 4 && month != 6 && month != 12)
			return false;

		if (Force(trgevent().getPerson().getForceId()).���� >= ����_�ָ�)
			return false;

		if (5 > Force(trgevent().getPerson().getForceId()).���ü�)
			return false;

		trglist<Person>()(0).init(����Ӽ�_����, trgevent().getPerson().getForceId());
		trglist<Person>()(0).remove(trgevent().getPerson());
		if (trglist<Person>()(0).size() < 20)
			return false;

		trglist<Person>()(1).init(����Ӽ�_����, trgevent().getPerson().getForceId());
		trglist<Person>()(1).remove(trgevent().getPerson());
		trglist<Person>()(1).remove_all_but(����Ӽ�_����, true);
		trglist<Person>()(1).remove_all_but(����Ӽ�_�ź�, �ź�_�Ϲ�);
		trglist<Person>()(1).remove_all_but(����Ӽ�_�Ǹ�, �Ǹ�_����, ������_�۰ų�����);
		trglist<Person>()(1).remove_all_but(����Ӽ�_�漺��, 100, ������_��������);
		if (trglist<Person>()(1).size() <= 0)
			return false;

		trglist<Person>()(2).clear();
		trglist<Person>()(3).clear();
		trglist<Person>()(0).init(����Ӽ�_����, trgevent().getPerson().getForceId());
		trglist<Person>()(0).remove(trgevent().getPerson());
		trglist<Person>()(0).remove_all_but(����Ӽ�_����, true);
		trglist<Person>()(0).remove_all_but(����Ӽ�_����, 10000, ������_ũ�ų�����);

		for (auto i = trglist<Person>()(0).begin(); i; i++)
		{
			if (!i().isCloseWith(trgevent().getPerson().getId()))
				trglist<Person>()(2).push_back(i());
		}

		for (auto i = trglist<Person>()(2).begin(); i; i++)
		{
			bool var1 = false;
			for (auto j = trglist<Person>()(1).begin(); j; j++)
			{
				if (j() == i() || j().isCloseWith(i().getId()) || j().isLike(i().getId()) || i().isLike(j().getId()))
					var1 = true;
			}
			if (!var1)
				trglist<Person>()(3).push_back(i());
		}

		return 0 < trglist<Person>()(3).size();
	}

	Person var0 = trglist<Person>()(1).random();
	Person var1 = trglist<Person>()(3).random();

	trgmsg().setPerson(2, trgevent().getPerson());
	trgmsg().setPerson(3, var0);
	trgmsg().setPerson(4, var1);
	trgsound().playBgm(20);
	trgscene().move(Building(trgevent().getPerson().�Ҽ�), 1000);
	trgsound().playSfx(601);
	trgmsg(18748, ����_����, trgevent().getPerson());
	trgmsg(18749, trgevent().getPerson(), ����_����);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(5);
	trgscene().eventStill(26);
	trgscene().fade(255);
	trgmsg(18750, trgevent().getPerson(), var0);
	trgmsg(18751, var0, trgevent().getPerson());
	trgmsg(18752, trgevent().getPerson(), var0);
	trgscene().closeEventStill();
	trgscene().effect(16);
	trgmsg(18753, var0, trgevent().getPerson());
	trgmsg(18754, trgevent().getPerson(), var0);
	trgmsg(18755, var0, trgevent().getPerson());

	trgdebate().init();
	trgdebate().setSlot(0, trgevent().getPerson(), true);
	trgdebate().setSlot(1, var0, false);
	trgdebate().run();
	bool var2 = trgdebate().getWinner() == 0;

	if (var2)
	{
		trgscene().fade(0);
		trgsleep();
		trgscene().background(5);
		trgscene().fade(255);
		trgmsg(18756, trgevent().getPerson(), var0);
		trgmsg(18757, var0, trgevent().getPerson());
		trgscene().effect(13);
		trgmsg(18758, trgevent().getPerson(), var0);
	}
	else
	{
		trgscene().fade(0);
		trgsleep();
		trgscene().background(5, 0);
		trgscene().fade(255);
		trgmsg(18759, trgevent().getPerson(), var0);
		trgscene().effect(17);
		trgmsg(18760, var0, trgevent().getPerson());
		trgscene().fade(0);
		trgsleep();
		trgscene().background(2, 0);
		trgscene().fade(255);
		trgmsg(18761, var1, trgevent().getPerson());
		trgsound().playSfx(610, 100);
		trgmsg(18762, trgevent().getPerson(), var1);
		trgmsg(18763, var1, trgevent().getPerson());
		trgscene().effect(13);
		trgmsg(18764, trgevent().getPerson(), var1);
		trgmsg(18765, var1, trgevent().getPerson());
	}

	trgmgr().setLastRunTime(115, Scenario().getDayCount());

	if (var2)
	{
		var1.addLoyalty(2 + (2 * var1.�Ǹ�));
	}
	else
	{
		var0.addKouseki(200);
		var0.addLoyalty(2 + (2 * var0.�Ǹ�));
		var1.addLoyalty(-5 - (2 * var1.�Ǹ�));
	}

	return true;
}

/** ���� ���� */
bool PK_�����̺�Ʈ81(bool cond)
{
	if (cond)
	{
		if (trgmgr().getElapsedDays(112) <= 90 && 1 <= trgmgr().getElapsedDays(112))
			return false;

		trglist<Person>()(1).clear();
		trglist<Person>()(0).init(����Ӽ�_����, trgevent().getPerson().getForceId());
		trglist<Person>()(0).remove_all_but(����Ӽ�_�ź�, �ź�_����, ������_��������);
		for (auto i = trglist<Person>()(0).begin(); i; i++)
		{
			switch (i().�������δɷ�)
			{
			case �ɷ�����2_����:
			case �ɷ�����2_��ġ:
			case �ɷ�����2_�ŷ�:
			case �ɷ�����2_����:
			case �ɷ�����2_����:
				if (Force(trgevent().getPerson().getForceId()).���� == i().getId())
					break;
				if (i().isDislike(Force(trgevent().getPerson().getForceId()).����))
					break;
				if (Person(Force(trgevent().getPerson().getForceId()).����).isDislike(i().getId()))
					break;
				trglist<Person>()(1).push_back(i());
				break;
			}
		}

		if (trglist<Person>()(1).size() <= 0)
			return false;

		if (!Person(Force(trgevent().getPerson().getForceId()).����).isIdle())
			return false;

		return randbool(10);
	}

	trglist<Person>()(1).sort(����Ӽ�_����, ����_��������);

	Person var0 = trglist<Person>()(1)[0];

	trgmsg().setPerson(2, var0);
	trgmsg().setPerson(3, Force(trgevent().getPerson().getForceId()).����);
	trgmsg().setCity(0, var0.�Ҽӵ���);
	trgsound().playBgm(18);
	trgscene().move(Building(var0.�Ҽ�));
	trgmsg(18814);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(5);
	trgscene().eventStill(23);
	int var1 = trgsound().playSfxLoop(614);
	trgscene().fade(255);
	trgmsg(18815, Force(trgevent().getPerson().getForceId()).����, var0);
	trgmsg(18816, var0, Force(trgevent().getPerson().getForceId()).����);
	trgscene().closeEventStill();
	trgscene().effect(17);
	trgmsg(18817, Force(trgevent().getPerson().getForceId()).����, var0);
	trgsound().stopSfxLoop(var1);

	trgdebate().init();
	trgdebate().setSlot(0, var0, true);
	trgdebate().setSlot(1, Force(trgevent().getPerson().getForceId()).����, false);
	trgdebate().run();
	bool var2 = trgdebate().getWinner() == 0;

	if (var2)
	{
		trgscene().fade(0);
		trgsleep();
		trgscene().background(5);
		trgscene().fade(255);
		trgmsg(18818, Force(trgevent().getPerson().getForceId()).����, var0);
		trgsound().playSfx(11);
		trgmsg(18819, var0, Force(trgevent().getPerson().getForceId()).����);
		trgscene().fade(0);
		trgsleep();
		trgscene().background(-1);
		trgsound().playSfx(10);
		trgmsg(18820);
		trgscene().fade(255);
	}
	else
	{
		trgscene().fade(0);
		trgsleep();
		trgscene().background(5);
		trgscene().fade(255);
		trgmsg(18821, Force(trgevent().getPerson().getForceId()).����, var0);
		trgsound().playSfx(12);
		trgmsg(18822, var0, Force(trgevent().getPerson().getForceId()).����);
		trgscene().fade(0);
		trgsleep();
		trgscene().background(-1);
		trgsound().playSfx(10);
		trgmsg(18823);
		trgscene().fade(255);
	}

	trgmgr().setLastRunTime(112, Scenario().getDayCount());

	if (var2)
	{
		var0.addKouseki(1000);
		var0.addStatExp(����ɷ�_����, 50);
		var0.addStatExp(����ɷ�_��ġ, 50);
		var0.addStatExp(����ɷ�_�ŷ�, 50);
	}
	else
	{
		var0.addStatExp(����ɷ�_����, 10);
		var0.addStatExp(����ɷ�_��ġ, 10);
		var0.addStatExp(����ɷ�_�ŷ�, 10);
	}
	return true;
}

/** ���� ���� */
bool PK_�����̺�Ʈ82(bool cond)
{
	if (cond)
	{
		if (trgmgr().getElapsedDays(113) <= 90 && 1 <= trgmgr().getElapsedDays(113))
			return false;

		trglist<Person>()(1).clear();
		trglist<Person>()(0).init(����Ӽ�_����, trgevent().getPerson().getForceId());
		trglist<Person>()(0).remove_all_but(����Ӽ�_�ź�, �ź�_����, ������_��������);
		for (auto i = trglist<Person>()(0).begin(); i; i++)
		{
			switch (i().�������δɷ�)
			{
			case �ɷ�����2_���:
			case �ɷ�����2_����:
			case �ɷ�����2_â��:
			case �ɷ�����2_�غ�:
			case �ɷ�����2_�뺴:
			case �ɷ�����2_�⺴:
				if (Force(trgevent().getPerson().getForceId()).���� == i().getId())
					break;
				if (i().isDislike(Force(trgevent().getPerson().getForceId()).����))
					break;
				if (Person(Force(trgevent().getPerson().getForceId()).����).isDislike(i().getId()))
					break;
				trglist<Person>()(1).push_back(i());
				break;
			}
		}

		if (trglist<Person>()(1).size() <= 0)
			return false;

		trglist<Person>()(2).clear();
		trglist<Person>()(0).init(����Ӽ�_���, true);
		trglist<Person>()(0).remove_all_but(����Ӽ�_�ɷ� + ����ɷ�_����, 70, ������_ũ�ų�����);
		trglist<Person>()(0).remove_all_but(����Ӽ�_����, true);
		trglist<Person>()(0).remove_all_but(����Ӽ�_ģ��, false, trgevent().getPerson().����);
		for (auto i = trglist<Person>()(0).begin(); i; i++)
		{
			for (auto j = trglist<Person>()(1).begin(); j; j++)
			{
				if (j().isCloseWith(i().getId()))
					continue;
				if (j().isDislike(i().getId()))
					continue;
				if (i().isDislike(j().getId()))
					continue;
				if (j().���� == i().����)
					continue;
				trglist<Person>()(2).push_back(i());
			}
		}

		if (trglist<Person>()(2).size() <= 0)
			return false;

		if (!Person(Force(trgevent().getPerson().getForceId()).����).isIdle())
			return false;

		if (!randbool(10))
			return false;
		return true;
	}

	trglist<Person>()(1).sort(����Ӽ�_����, ����_��������);

	Person var0 = trglist<Person>()(1)[0];
	Person var1 = trglist<Person>()(2).random();

	trgmsg().setPerson(2, var0);
	trgmsg().setPerson(3, var1);
	trgmsg().setCity(0, var0.�Ҽӵ���);
	trgsound().playBgm(18);
	trgscene().move(Building(var0.�Ҽ�), 1000);
	trgmsg(18824);
	trgscene().fade(0);
	trgsleep();
	trgscene().background(3);
	int var2 = trgsound().playSfxLoop(608);
	trgscene().fade(255);
	trgsound().playSfx(606);
	trgsound().playSfx(606);
	trgmsg(18825, var0);
	trgsound().playSfx(601);
	trgscene().effect(20);
	trgmsg(18826, var0);
	trgmsg(18827, var1, var0, 15093);
	trgmsg(18828, var0, var1);
	trgsound().playSfx(610, 100);
	trgmsg(18829, var1, var0, 15093);
	trgmsg(18830, var0, var1);
	trgmsg(18831, var1, var0);
	trgscene().effect(17);
	trgmsg(18832, var0, var1);
	trgsound().stopSfxLoop(var2);

	trgduel().init();
	trgduel().setSlot(0, 0, var0);
	trgduel().setSlot(1, 0, var1);
	trgduel().setControl(0, 0);
	trgduel().run(1);
	bool var3 = trgduel().getWinner() == 0;

	if (var3)
	{
		trgscene().fade(0);
		trgsleep();
		trgscene().background(3);
		trgscene().fade(255);
		trgmsg(18833, var1, var0);
		trgsound().playSfx(11);
		trgmsg(18834, var0, var1);
		trgscene().fade(0);
		trgsleep();
		trgscene().background(-1);
		trgsound().playSfx(10);
		trgmsg(18835);
		trgscene().fade(255);
	}
	else
	{
		trgscene().fade(0);
		trgsleep();
		trgscene().background(3);
		trgscene().fade(255);
		trgmsg(18836, var1, var0);
		trgsound().playSfx(12, 100);
		trgmsg(18837, var0, var1);
		trgscene().fade(0);
		trgsleep();
		trgscene().background(-1);
		trgsound().playSfx(10);
		trgmsg(18838);
		trgscene().fade(255);
	}

	trgmgr().setLastRunTime(113, Scenario().getDayCount());

	if (var3)
	{
		var0.addKouseki(200);
		var0.addStatExp(����ɷ�_���, 25);
		var0.addStatExp(����ɷ�_����, 25);
		var0.addWeaponExp(����_â, 25);
		var0.addWeaponExp(����_��, 25);
		var0.addWeaponExp(����_��, 25);
		var0.addWeaponExp(����_����, 25);
		var1.setLocation(var0.�Ҽ�);
		var1.changeForce(trgevent().getPerson().getForceId(), var0, 0);
		var1.addKouseki(200);
		var1.setLoyalty(var0.�漺��);
	}
	else
	{
		var0.addStatExp(����ɷ�_���, 10);
		var0.addStatExp(����ɷ�_����, 10);
		var0.addWeaponExp(����_â, 10);
		var0.addWeaponExp(����_��, 10);
		var0.addWeaponExp(����_��, 10);
		var0.addWeaponExp(����_����, 10);
	}

	return true;
}