/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dictionary;

import java.io.*;
import java.util.Scanner;
import java.util.HashMap;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
/**
 * 
* @author miguelguardado
 */
public class Dictionary {
    public static final HashMap<String,String[]> word = new HashMap<String, String[]>();
    private static EnumLibrary Word;
    public Dictionary(EnumLibrary Word){
        this.Word=Word;
    }
 
    public static void LoadData(){
        //this function loads the enum database onto the hashmap
        for(EnumLibrary dir:EnumLibrary.values()){
            String[] PartsofSpeech= new String[12];
            PartsofSpeech[1]=dir.adjective;
            PartsofSpeech[2]=dir.adjective2;
            PartsofSpeech[3]=dir.conjunction;
            PartsofSpeech[4]=dir.interjection;
            PartsofSpeech[5]=dir.noun1;
            PartsofSpeech[6]=dir.noun2;
            PartsofSpeech[7]=dir.noun3;
            PartsofSpeech[8]=dir.preposition;
            PartsofSpeech[9]=dir.pronoun;
            PartsofSpeech[10]=dir.verb1;
            PartsofSpeech[11]=dir.verb2;
            word.put(dir.name(), PartsofSpeech);
        }
    }
    //this function goes though the index to assign a certain part of speech
    public static String getPOS(int index){
        String returnValue=" ";
        switch(index){
                case 1:
                case 2:
                    returnValue="adjective";
                    break;
                case 3:
                    returnValue="conjunction";
                    break;
                case 4:
                    returnValue="interjection";
                    break;
                case 5:
                case 6:
                case 7:
                    returnValue="noun";
                    break;
                case 8:
                    returnValue="preposition";
                    break;
                case 9:
                    returnValue="pronoun";
                    break;
                case 10:
                case 11:
                    returnValue="verb";
                    break; 
                default:
                    break;         
        }  
        return returnValue;
    }
    public static void checkdef(String[] inputarr){
        //if we have a length of one we know we want to print the entire word    
        if(inputarr.length==1){
            sortDef(inputarr[0]);
            return;
        }else{
            //if we get here then we are dealing with a part of speech
        for(int i=1;i<(word.get(inputarr[0]).length);i++){
            if(getPOS(i).equals(inputarr[1])){
                printdef(inputarr[0],i);
                return;
            }
            }
        printdeferror();
        }
    }

    public static void sortDef(String input){
        System.out.println("|");
        //if input is no match in the dictionary print error messege and return to main
            if(word.get(input)==null){
                printdeferror();
                return;
            }
         for(int i=1;i<(word.get(input).length);i++){
             if(!(word.get(input)[i]).equals(" ")){
                 printdef(input,i);
                 
             }
         }
         System.out.println("|");
    }
    public static void printdef(String input, int ValIndex){
        System.out.println(input+" "+"["+getPOS(ValIndex)+"]"+" : "+word.get(input)[ValIndex]);
    }
    public static void printdeferror(){
        System.out.println("<Not found>");
    }
    //read a file and assign it all to a data file.
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args){
        Scanner scan=new Scanner(System.in);
        System.out.println("! Loading Data....");
        Dictionary.LoadData();
        System.out.println("! Loading Complete");
        System.out.println(" ");
        System.out.println("-----DICTIONARY 340-----");
        System.out.print(' ');
        String input=" ";
        String[] inputarr={" "};
        while(true){
            System.out.print("Search: ");
            inputarr=(scan.nextLine()).split("\\s");
            inputarr[0]=inputarr[0].toUpperCase();
            if(inputarr[0].equals("!Q")){
                break;
            }
            Dictionary.checkdef(inputarr);
        }
        System.out.println("----THANK YOU----");
    }

    
    
}
