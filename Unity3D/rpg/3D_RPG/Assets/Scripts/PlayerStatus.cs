﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class PlayerStatus : MonoBehaviour
{
    Animator animator;
    private int level;
    public float maxHp = 100;
    private float curHp;
    public float maxMp = 100;
    private float curMp;
    public float maxExp = 100;
    private float curExp;
    public bool dead = false;
    public Slider hpSlider;
    public Slider mpSlider;
    public Slider expSlider;
    public Text levelText;
    // Start is called before the first frame update
    void Start()
    {
        level = 1;
        animator = GetComponent<Animator>();
        curHp = maxHp;
        curMp = maxMp;
        curExp = 0;
        hpSlider.value = curHp / maxHp;
        mpSlider.value = curMp / maxMp;
        expSlider.value = curExp / maxExp;
        levelText.text = "Lv." + level;
    }

    // Update is called once per frame
    void Update()
    {

    }

    public void OnDamage(float damage)
    {
        if (dead)
            return;
        curHp -= damage;
        if (curHp <= 0)
        {
            dead = true;
            animator.SetTrigger("Dead");
        }
        hpSlider.value = curHp / maxHp;
    }
    public void GetExp(float exp)
    {
        curExp += exp;
        if (curExp >= maxExp)
        {
            level++;
            curExp -= maxExp;
            maxExp = maxExp * 1.2f;
            maxHp = maxHp * 1.2f;
            curHp = maxHp;
            maxMp = maxMp * 1.2f;
            curMp = maxMp;
            levelText.text = "Lv." + level;
            hpSlider.value = curHp / maxHp;
            mpSlider.value = curMp / maxMp;
        }
        expSlider.value = curExp / maxExp;
    }
}
