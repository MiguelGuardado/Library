/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dictionary;

/**
 *
 * @author miguelguardado
 */
public enum EnumLibrary{
    
    PLACEHOLDER("To be Updated...","To be Updated...","To be Updated...","To be Updated...","To be Updated...",
            "To be Updated...","To be Updated...","To be Updated...","To be Updated...","To be Updated..."," ")
    ,CSC210("Comfortable with Objects and Classes","Ready for CSC220"," "," ","Intro to Java"," "," "," "," ","To Learn Java"," ")
    ,CSC220("Ready to create complex Data Structures"," "," "," ","Data Structures "," "," "," "," ","To create Data Structures"," ")
    ,CSC340("C++ version of CSC210 + CSC220 + more"," "," "," ", "CS upper divison course","Many hours outside of class","Programing Methodology"," "," "," "," ")
    ,VERB(" "," "," "," ","Verb is a word or group of words that expresses and action(such as eat)"
            + ",an event(such as happen), or a state(Such as exist)"," "," "," "," "," "," ")
    ,BOOK(" "," "," "," ","A set of pages.","A written work published in printed or electronic form" ," "," ","To arrange for someone to have a seat on a plane.","A written work published in printed or electronic form."," ")
    ,BOOKABLE("Can be ordered in advanced"," "," "," "," "," "," "," "," "," "," ")
    ,CONJUNCTION(" "," "," "," ","Conjection is a word that joins words, phrases or sentences, for example 'and','but', 'or'"," "," "," "," "," "," ")
    ,INTERJECTION(" "," "," "," ","Interjection is a short sound, word or phrases spoken suddenly to express an emotion. Oh!, Look out! and OW! are intetjections"," "," "," "," "," "," ")  
    ,ADJECTIVE(" "," "," "," ","Adjective is a word that describes a person or thing, for example big, red and clever in a big house, red wine and a clever idea"," "," "," "," "," "," ");
    
    
    public String[] POSarray;
    public String adjective;//1-2
    public String adjective2;//1-2
    public String conjunction;//3
    public String interjection;//4
    public String noun1;//5-6-7
    public String noun2;//5-6-7
    public String noun3;//5-6-7
    public String preposition;//8
    public String pronoun;//9
    public String verb1;//10-11
    public String verb2;//10-11
    
    
    EnumLibrary(String adjective,String adjective2,String conjunction,String interjection,String noun1,String noun2,String noun3,String preposition, String pronoun, String verb1,String verb2){
        this.adjective=adjective;
        this.adjective2=adjective2;
        this.conjunction=conjunction;
        this.interjection=interjection;
        this.noun1=noun1;
        this.noun2=noun2;
        this.noun3=noun3;
        this.preposition=preposition;
        this.pronoun=pronoun;
        this.verb1=verb1;
        this.verb2=verb2;
    }
    EnumLibrary(){
        
    }
    
}

    