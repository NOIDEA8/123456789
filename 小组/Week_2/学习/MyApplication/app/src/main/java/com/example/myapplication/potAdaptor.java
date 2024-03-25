package com.example.myapplication;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import androidx.recyclerview.widget.RecyclerView;

import java.util.List;


public class potAdaptor extends RecyclerView.Adapter<potAdaptor.ViewHolder> {
    private List<pot> mpotList;
    static class ViewHolder extends RecyclerView.ViewHolder{
        View potview;
        ImageView potImage;
        TextView potname;
        public ViewHolder(View View) {
            super(View);
            potview=View;
            potname=(TextView) View.findViewById(R.id.name1);
            potImage=(ImageView) View.findViewById(R.id.image1);
        }
    }//建立内部类viewfolder继承自recyclerview
    public  potAdaptor(List<pot> potlist){
        mpotList=potlist;
    }//构造方法
    @Override
    public ViewHolder onCreateViewHolder(ViewGroup parent,int viewType){
        View view= LayoutInflater.from(parent.getContext()).inflate(R.layout.pot,parent,false);
        final ViewHolder holder=new ViewHolder(view);
        holder.potview.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int position=holder.getBindingAdapterPosition();
                pot pot=mpotList.get(position);
                Toast.makeText(v.getContext(),"You click view"+mpotList.get(position).getName(), Toast.LENGTH_SHORT).show();
            }
        });
        holder.potname.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int position=holder.getBindingAdapterPosition();
                pot pot=mpotList.get(position);
                Toast.makeText(v.getContext(),"You click name"+mpotList.get(position).getName(), Toast.LENGTH_SHORT).show();
            }
        });
        holder.potImage.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int position=holder.getBindingAdapterPosition();
                pot pot=mpotList.get(position);
                Toast.makeText(v.getContext(),"You click image"+mpotList.get(position).getName(), Toast.LENGTH_SHORT).show();
            }
        });
        return holder;
    }//为viewholder建模
    @Override
    public void onBindViewHolder(ViewHolder holder,int position){
        pot pot=mpotList.get(position);
        holder.potImage.setImageResource(pot.getImgid());
        holder.potname.setText(pot.getName());
    }//为viewfolder赋值
    @Override
    public int getItemCount(){
        return mpotList.size();
    }//展示内容容量
}
