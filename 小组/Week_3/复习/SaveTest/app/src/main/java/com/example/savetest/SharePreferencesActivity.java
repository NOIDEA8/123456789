package com.example.savetest;

import androidx.appcompat.app.AppCompatActivity;

import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class SharePreferencesActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_share_preferences);
        Button save=(Button) findViewById(R.id.save);
        Button load=(Button) findViewById(R.id.load);
        final SharedPreferences[] sp = {null};
        save.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sp[0] =save();
            }
        });
        load.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
               load(sp[0]);
            }
        });
    }
    private SharedPreferences save(){
        SharedPreferences sp=getSharedPreferences("data",0);
        SharedPreferences.Editor editor=sp.edit();
        editor.putString("行为","I know nothing!");
        editor.putString("慨叹","There is much knowledge to learn!");
        editor.apply();
        return sp;
    }
    private void load(SharedPreferences sp){
        if(sp==null){
            Toast.makeText(SharePreferencesActivity.this, "你还没存储信息",Toast.LENGTH_SHORT).show();
        }else {
            EditText editText = findViewById(R.id.edittext);
            sp.getString("行为", "");

            Toast.makeText(SharePreferencesActivity.this,
                    "行为：" + sp.getString("行为", ""), Toast.LENGTH_SHORT).show();
            editText.setText(sp.getString("慨叹", ""));
        }
    }
}