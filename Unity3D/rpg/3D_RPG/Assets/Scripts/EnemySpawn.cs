﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemySpawn : MonoBehaviour
{
    public int maxEnemyCount = 3;
    public GameObject enemyPrefab;
    private GameObject[] enemies;
    public float spawnDelay = 7.0f;
    private float curTime;
    // Start is called before the first frame update
    void Start()
    {
        enemies = new GameObject[maxEnemyCount];
        curTime = 0;
    }

    // Update is called once per frame
    void Update()
    {
        curTime += Time.deltaTime;
        if(curTime >= spawnDelay)
        {
            SpawnEnemy();
            curTime = 0;
        }
    }

    void SpawnEnemy()
    {
        for(int i = 0; i < enemies.Length; i++)
        {
            if(enemies[i] == null)
            {
                enemies[i] = Instantiate(enemyPrefab, transform.position, transform.rotation);
                break;
            }
        }
    }
}
