#include <iostream>
#include <string>
#include <string_view>
#include <regex>

using namespace std::string_literals;

std::string encoded = R"(                                     #in                                                                                                                             
                                                              clu                                                                                                                             
                                                              de$                                                                                                                             
                                                              SPA                                                                                                                             
                                                              CE<                                                                  i             o                                            
                                                              str                                                                eam           >$N                                            
                                                              EWL                                                                INE           #in                                            
                                                              clu                                                                de$           SPA                                            
                                                              CE<                                                                str           ing                                            
                                                              >$N                                                                EWL           INE                                            
#inc    lud          e$SPAC                 E<strin           g_v        iew>          $NEWLIN          E#in          clud    e$SPACE<rege  x>$NEWLINE$N         EWLINEu           sing    $SP
ACEn  amesp       ace$SPACEstd            ::string_li         ter       als;         $NEWLINE$NE        WLIN          Estd    ::string$SPA  CEencoded$SP       ACE=$SPACE{         }{}{  };$NE
WLIN E$NEWL      INEstd::string          $SPACERemoveSp       ace      (con         st$SPACEstd::s      trin          g&$S    PACEstr){$NE  WLINE$TABret      urn$SPACEstd:        :reg ex_rep
lace (str,      $SPACE    std::r        egex("    $SPAC       E")     ,$SP         ACE"")    ;$NEW      LINE          }$NE       WLI           NE$           NEWLI     NEstd       ::st ring$ 
SPACERem       oveNe        wLine      (cons        t$SP      ACE    std:         :stri        ng&$     SPAC          Estr       ){$           NEW          LINE$       TABre      turn$SPA   
CEstd:         :reg          ex_r      epla          c        e(s   tr,$          SPAC          E       std:          :reg       ex(           "\n          "),$         SPAC      E"");$     
NEWLI         NE}$            NEWL    INE$                    NEW  LINE          std:                   :str          ing$       SPA           CER         esto           reS      tring      
(std:         :str            ing$    SPAC                    Est  r){           $NEW                   LINE          $TAB       sta           tic         $SPA           CEco     nst$S      
PACE          std:            :str    ing$                    SPA CESP           ACE_                   TOKE          N$TA       B$T           AB=         $SPACE"\\$"s$SPACE+     $SPA       
CE"S          PACE            ";$N    EWLI                    NE$TABst           atic                   $SPA          CEco       nst           $SP         ACEstd::string$SPAC     ETAB       
_TOK          EN$T            AB$T    AB$S                    PACE$SPAC          E=$S                   PACE          "\\$       "s$           SPA         CE+$SPACE"TAB";$NEW     LINE       
$TAB          stat            ic$S    PACE                    cons  t$SP         ACEs                   td::          stri       ng$           SPA         CENE                    WLIN       
E_TO          KEN$            TAB$    SPAC                    E$S    PACE        =$SP                   ACE"          \\$"       s$S           PAC         E+$S                    PACE       
"NEW          LINE            ";$N    EWLI                    NE$    TABs        tati                   c$SP         ACEco       nst           $SP         ACEs                    td::       
stri           ng$S          PACE      SPAC          E_       CHA     RACT        ER$T          AB      =$SP         ACE"$       SPA           CE"          ;$NE                   WLIN       
E$TA           Bstat        ic$SP      ACEco        nst$      SPA      CEst       d::st        ring      $SPA       CETAB_       CHAR          ACTE         RS$TA         B$S      PACE       
=$SP            ACE"$T    AB";$N        EWLINE     $TABs      tat       ic$S       PACEco     nst$S      PACEs    td::stri       ng$S          PACE          NEWLIN     E_CHA      RACT       
ERS$             SPACE=$SPACE"\          n";$NEWLINE$TA       Bst       r$SP        ACE=$SPACEstd:        :regex_repl ace(       str,$SPAC     Estd::reg      ex(SPACE_TOKEN)      ,$SP       
ACES              PACE_CHARACT            ER);$NEWLINE        $TA        Bstr        $SPACE=$SPAC         Estd::rege  x_re        place(st      r,$SPACE       std::regex(T        AB_T       
OKEN                ),$SPACE                TAB_CHAR          ACT         ERS)         ;$NEWLIN             E$TABs    tr$S         PACE=$        SPACEs          td::rege          x_re       
place(str,$SPACEstd::regex(NEWLINE_TOKEN),$SPACENEWLINE_CHARACTERS);$NEWLINE$TABreturn$SPACEstr;$NEWLINE}$NEWLINE$NEWLINEstd::string$SPACEMiniFormat(std::string_view$SPACEcontent,$SPACEstd::string$SPACEarg,$SPACEsize_t$SPACEindex$SPACE=$SPACE0){$NEWLINE$TABauto$SPACEformatPoint$SPACE=$SPACEcontent.find("{}");$NEWLINE$TABfor(size_t$SPACEi$SPACE=$SPACE0;$SPACEi$SPACE<$SPACEindex;$SPACE++i){$NEWLINE$TAB$TABformatPoint$SPACE=$SPACEcontent.find("{}",$SPACEformatPoint$SPACE+$SPACE1);$NEWLINE$TAB}$NEWLINE$TAB$NEWLINE$TABauto$SPACEformer$SPACE=$SPACEcontent.substr(0,$SPACEformatPoint);$NEWLINE$TABauto$SPACElatter$SPACE=$SPACEcontent.substr(formatPoint$SPACE+$SPACE2);$NEWLINE$TABreturn$SPACEstd::string{former}$SPACE+$SPACEarg$SPACE+$SPACEstd::string{latter};$NEWLINE}$NEWLINE$NEWLINEint$SPACEmain(){$NEWLINE$TABauto$SPACEdecoded$SPACE=$SPACERestoreString(RemoveSpace(RemoveNewLine(encoded)));$NEWLINE$TABstd::string$SPACEoutString;$NEWLINE$TABoutString$SPACE=$SPACEMiniFormat(decoded,$SPACE"R\"(");$NEWLINE$TABoutString$SPACE=$SPACEMiniFormat(outString,$SPACE")\"",$SPACE1);$NEWLINE$TABoutString$SPACE=$SPACEMiniFormat(outString,$SPACEencoded);$NEWLINE$TABstd::cout$SPACE<<$SPACEoutString;$NEWLINE}$NEWLINE)";

std::string RemoveSpace(const std::string& str){
    return std::regex_replace(str, std::regex(" "), "");
}

std::string RemoveNewLine(const std::string& str){
    return std::regex_replace(str, std::regex("\n"), "");
}

std::string RestoreString(std::string str){
    static const std::string SPACE_TOKEN        = "\\$"s + "SPACE";
    static const std::string TAB_TOKEN          = "\\$"s + "TAB";
    static const std::string NEWLINE_TOKEN      = "\\$"s + "NEWLINE";
    static const std::string SPACE_CHARACTER    = " ";
    static const std::string TAB_CHARACTERS     = "    ";
    static const std::string NEWLINE_CHARACTERS = "\n";
    str = std::regex_replace(str, std::regex(SPACE_TOKEN), SPACE_CHARACTER);
    str = std::regex_replace(str, std::regex(TAB_TOKEN), TAB_CHARACTERS);
    str = std::regex_replace(str, std::regex(NEWLINE_TOKEN), NEWLINE_CHARACTERS);
    return str;
}

std::string MiniFormat(std::string_view content, std::string arg, size_t index = 0){
    auto formatPoint = content.find("{}");
    for(size_t i = 0; i < index; ++i){
        formatPoint = content.find("{}", formatPoint + 1);
    }
    
    auto former = content.substr(0, formatPoint);
    auto latter = content.substr(formatPoint + 2);
    return std::string{former} + arg + std::string{latter};
}

int main(){
    auto decoded = RestoreString(RemoveSpace(RemoveNewLine(encoded)));
    std::string outString;
    outString = MiniFormat(decoded, "R\"(");
    outString = MiniFormat(outString, ")\"", 1);
    outString = MiniFormat(outString, encoded);
    std::cout << outString;
}
