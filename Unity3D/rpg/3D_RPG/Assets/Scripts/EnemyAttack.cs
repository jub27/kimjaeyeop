﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyAttack : MonoBehaviour
{
    public GameObject weapon;
    CapsuleCollider cc;
    public float power;
    // Start is called before the first frame update
    void Start()
    {
        cc = weapon.GetComponent<CapsuleCollider>();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnTriggerEnter(Collider other)
    {
        cc.enabled = false;
    }

    public void AttackEnable()
    {
        cc.enabled = true;
    }

    public void AttackDisable()
    {
        cc.enabled = false;
    }
}
