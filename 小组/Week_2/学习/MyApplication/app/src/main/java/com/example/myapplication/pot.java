package com.example.myapplication;

import android.widget.ImageView;
import android.widget.TextView;

public class pot {
    private int imgid;
    private String name;
    public pot(String name,int imgid){
        this.name=name;
        this.imgid=imgid;
    }
    public int getImgid(){
        return this.imgid;
    }
    public String getName(){
        return this.name;
    }

}
