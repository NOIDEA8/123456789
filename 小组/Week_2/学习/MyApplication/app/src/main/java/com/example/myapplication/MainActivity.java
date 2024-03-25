package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import androidx.recyclerview.widget.StaggeredGridLayoutManager;

import android.os.Bundle;
import android.widget.LinearLayout;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {
    private final List<pot> potList=new ArrayList<>();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        initpots();
        RecyclerView recyclerView=(RecyclerView) findViewById(R.id.recyclerview);
        StaggeredGridLayoutManager lom=new StaggeredGridLayoutManager(10,StaggeredGridLayoutManager.VERTICAL);
        recyclerView.setLayoutManager(lom);
        potAdaptor adaptor=new potAdaptor(potList);
        recyclerView.setAdapter(adaptor);
    }
    private void initpots(){
        for (int i = 0; i < 9; i++) {
            pot a=new pot("ahkjfsssssssssssssssss",R.drawable.pot1);
            potList.add(a);
            pot b=new pot("bafffffffffffffffffffffffffffffffffffff",R.drawable.pot2);
            potList.add(b);
            pot c=new pot("caffffffffffffffffffffffffffff",R.drawable.pot3);
            potList.add(c);
            pot d=new pot("dfaaaaaaaaaaaaaaaaaaaa",R.drawable.pot4);
            potList.add(d);
            pot e=new pot("eewaaaffffffffffffffffffffffffff",R.drawable.pot5);
            potList.add(e);
            pot f=new pot("freggggggggggggggggggggggggggg",R.drawable.pot6);
            potList.add(f);
            pot g=new pot("gweeeeeeeeeeeeeeeeeeeeeeeeeee",R.drawable.pot7);
            potList.add(g);
            pot h=new pot("hshhhhhhhhhhhd",R.drawable.pot8);
            potList.add(h);
            pot i1=new pot("ishhhhhhhhhhhhhhhhhhhhh",R.drawable.pot9);
            potList.add(i1);
            pot j=new pot("jshhhhhhhhhhhhhhhhhhres",R.drawable.pot10);
            potList.add(j);
        }
    }
}