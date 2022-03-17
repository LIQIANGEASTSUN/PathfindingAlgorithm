using UnityEngine;
using System.Collections;
using System.IO;
using System.Collections.Generic;
using CommonUtils;
using System.Text;

public class ConfigLoad : MonoBehaviour
{
    public static ConfigLoad Instance;

    public delegate void configLoadOverHandle();

    private string title;
    private string textContent;
    private byte[] byteData;
    private List<string> configList;
    private List<string> behaviorCfgList;
    private int totleConfigNum;

    public void Awake()
    {
        Instance = this;
    }

    private void RegisterConfigs()
    {
        configList = new List<string>();
        configList.Add("labyrinth1.csv");
        configList.Add("labyrinth2.csv");

        behaviorCfgList = new List<string>() { "behavior_tree_config.bytes" };
        totleConfigNum = configList.Count + behaviorCfgList.Count;
    }

    private IEnumerator LoadConfig(configLoadOverHandle handler)
    {
        for (int i = 0; i < configList.Count; i++)
        {
            yield return StartCoroutine(LoadData("CSVAssets", configList[i], 0));
            TableDatas.LoadCsv(title, textContent);
        }

        for (int i = 0; i < behaviorCfgList.Count; ++i)
        {
            yield return StartCoroutine(LoadData("Bina", behaviorCfgList[i], 1));
            //DataCenter.behaviorData.LoadData(byteData);
        }

        handler?.Invoke();
    }

    StringBuilder _sb = new StringBuilder();
    float _startTime;
    IEnumerator LoadData(string directory, string name, int type)
    {
        string path = FileUtils.GetStreamingAssetsFilePath(name, directory);

        WWW www = new WWW(path);
        yield return www;
        title = name.Substring(0, name.LastIndexOf("."));

        if (type == 0)
        {
            textContent = www.text;
        }
        else
        {
            byteData = www.bytes;
        }
        yield return true;
    }

    public void Load(configLoadOverHandle handler)
    {
        RegisterConfigs();
        StartCoroutine(LoadConfig(handler));
    }

}

