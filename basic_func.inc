Function distance_agt(agt1 as Agt, agt2 as Agt) as Double{
//２つのエージェントの間の距離を取得する関数

//空間を取得する（agt1の空間を取得して距離計算に使う）
Dim sp as Space
Dim agt_type as AgtType
agt_type=SpecifyAgtType(agt1)
sp=GetRideSpace(agt_type)

//距離を計算する
dim distance as Double
distance=MeasureDistance(agt1.X, agt1.Y, agt2.X, agt2.Y, sp)

return(distance)

}

//----------------------------------------------------------
Function direction_agt(agt1 as Agt, agt2 as Agt) as Double{
//agt1から見たagt2の角度を取得する関数[degree]

//空間を取得する（agt1の空間を取得して角度計算に使う）
Dim sp as Space
Dim agt_type as AgtType
agt_type=SpecifyAgtType(agt1)
sp=GetRideSpace(agt_type)

//角度を計算する
dim direction as Double
direction=GetDirection(agt1.X, agt1.Y, agt2.X, agt2.Y, sp)

return(direction)

}

//----------------------------------------------------------
Function AgtTypeComp(agt1 as Agt, agt2 as Agt) as Integer{
//agt1とagt2のタイプが一致するとき1，一致しないとき0を出力する

Dim agt_type1 as String
Dim agt_type2 as String
Dim answer as Integer

//それぞれのエージェントタイプを文字列として取得する
agt_type1=CStr(SpecifyAgtType(agt1))
agt_type2=CStr(SpecifyAgtType(agt2))

//文字列が一致していれば1，一致していなければ0を出力する
If StrComp(agt_type1,agt_type2)==0 then
	answer=1
Else

	answer=0

End if

return(answer)

}

//----------------------------------------------------------
Function AgtTypeComp2(agt1 as Agt, agt_type_str as String) as Integer{
//agt1のタイプ名がagt_type_strと一致するとき1，一致しないとき0を出力する
//agt_type_strは"Universe.空間名.種別名"という形で記述する

Dim agt_type as String
Dim answer as Integer

//それぞれのエージェントタイプを文字列として取得する
agt_type=CStr(SpecifyAgtType(agt1))

//文字列が一致していれば1，一致していなければ0を出力する
If StrComp(agt_type,agt_type_str)==0 then
	answer=1
Else

	answer=0

End if

return(answer)

}

//----------------------------------------------------------
Function eRnd(e as Double) as Double{
//-e〜+eの範囲の値をランダム(一様分布)で返す

Dim output as Double

output = 2*e*(Rnd()-0.5) 

return(output)

}