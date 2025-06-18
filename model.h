#ifndef UUID3103132161536
#define UUID3103132161536

/**
  * RandomForestClassifier(bootstrap=True, ccp_alpha=0.0, class_name=RandomForestClassifier, class_weight=None, criterion=gini, estimator=DecisionTreeClassifier(), estimator_params=('criterion', 'max_depth', 'min_samples_split', 'min_samples_leaf', 'min_weight_fraction_leaf', 'max_features', 'max_leaf_nodes', 'min_impurity_decrease', 'random_state', 'ccp_alpha', 'monotonic_cst'), max_depth=None, max_features=sqrt, max_leaf_nodes=None, max_samples=None, min_impurity_decrease=0.0, min_samples_leaf=1, min_samples_split=2, min_weight_fraction_leaf=0.0, monotonic_cst=None, n_estimators=10, n_jobs=None, num_outputs=3, oob_score=False, package_name=everywhereml.sklearn.ensemble, random_state=None, template_folder=everywhereml/sklearn/ensemble, verbose=0, warm_start=False)
 */
class RandomForestClassifier {
    public:

        /**
         * Predict class from features
         */
        int predict(float *x) {
            int predictedValue = 0;
            size_t startedAt = micros();

            
                    
            float votes[3] = { 0 };
            uint8_t classIdx = 0;
            float classScore = 0;

            
                tree0(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree1(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree2(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree3(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree4(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree5(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree6(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree7(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree8(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree9(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            

            uint8_t maxClassIdx = 0;
            float maxVote = votes[0];

            for (uint8_t i = 1; i < 3; i++) {
                if (votes[i] > maxVote) {
                    maxClassIdx = i;
                    maxVote = votes[i];
                }
            }

            predictedValue = maxClassIdx;

                    

            latency = micros() - startedAt;

            return (lastPrediction = predictedValue);
        }

        
            
            /**
             * Get latency in micros
             */
            uint32_t latencyInMicros() {
                return latency;
            }

            /**
             * Get latency in millis
             */
            uint16_t latencyInMillis() {
                return latency / 1000;
            }
            

    protected:
        float latency = 0;
        int lastPrediction = 0;

        
            
        
            
                /**
                 * Random forest's tree #0
                 */
                void tree0(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[2] < 0.5) {
                            
                        if (x[29] < 0.5) {
                            
                        if (x[13] < 0.5) {
                            
                        if (x[7] < 0.5) {
                            
                        *classIdx = 1;
                        *classScore = 0.24390243902439024;
                        return;

                        }
                        else {
                            
                        *classIdx = 2;
                        *classScore = 0.36585365853658536;
                        return;

                        }

                        }
                        else {
                            
                        if (x[12] < 0.5) {
                            
                        *classIdx = 0;
                        *classScore = 0.3902439024390244;
                        return;

                        }
                        else {
                            
                        *classIdx = 2;
                        *classScore = 0.36585365853658536;
                        return;

                        }

                        }

                        }
                        else {
                            
                        if (x[22] < 0.5) {
                            
                        *classIdx = 2;
                        *classScore = 0.36585365853658536;
                        return;

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.3902439024390244;
                        return;

                        }

                        }

                        }
                        else {
                            
                        if (x[4] < 0.5) {
                            
                        *classIdx = 0;
                        *classScore = 0.3902439024390244;
                        return;

                        }
                        else {
                            
                        if (x[1] < 0.5) {
                            
                        *classIdx = 0;
                        *classScore = 0.3902439024390244;
                        return;

                        }
                        else {
                            
                        if (x[8] < 0.5) {
                            
                        *classIdx = 2;
                        *classScore = 0.36585365853658536;
                        return;

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.3902439024390244;
                        return;

                        }

                        }

                        }

                        }

                }
            
        
            
                /**
                 * Random forest's tree #1
                 */
                void tree1(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[2] < 0.5) {
                            
                        if (x[13] < 0.5) {
                            
                        *classIdx = 1;
                        *classScore = 0.24390243902439024;
                        return;

                        }
                        else {
                            
                        if (x[26] < 0.5) {
                            
                        *classIdx = 0;
                        *classScore = 0.3170731707317073;
                        return;

                        }
                        else {
                            
                        if (x[27] < 0.5) {
                            
                        *classIdx = 0;
                        *classScore = 0.3170731707317073;
                        return;

                        }
                        else {
                            
                        *classIdx = 2;
                        *classScore = 0.43902439024390244;
                        return;

                        }

                        }

                        }

                        }
                        else {
                            
                        if (x[1] < 0.5) {
                            
                        *classIdx = 0;
                        *classScore = 0.3170731707317073;
                        return;

                        }
                        else {
                            
                        if (x[4] < 0.5) {
                            
                        *classIdx = 0;
                        *classScore = 0.3170731707317073;
                        return;

                        }
                        else {
                            
                        *classIdx = 2;
                        *classScore = 0.43902439024390244;
                        return;

                        }

                        }

                        }

                }
            
        
            
                /**
                 * Random forest's tree #2
                 */
                void tree2(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[28] < 0.5) {
                            
                        if (x[17] < 0.5) {
                            
                        if (x[5] < 0.5) {
                            
                        *classIdx = 1;
                        *classScore = 0.1951219512195122;
                        return;

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.3902439024390244;
                        return;

                        }

                        }
                        else {
                            
                        if (x[15] < 0.5) {
                            
                        if (x[13] < 0.5) {
                            
                        *classIdx = 2;
                        *classScore = 0.4146341463414634;
                        return;

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.3902439024390244;
                        return;

                        }

                        }
                        else {
                            
                        *classIdx = 2;
                        *classScore = 0.4146341463414634;
                        return;

                        }

                        }

                        }
                        else {
                            
                        if (x[9] < 0.5) {
                            
                        *classIdx = 0;
                        *classScore = 0.3902439024390244;
                        return;

                        }
                        else {
                            
                        if (x[20] < 0.5) {
                            
                        if (x[1] < 0.5) {
                            
                        *classIdx = 2;
                        *classScore = 0.4146341463414634;
                        return;

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.3902439024390244;
                        return;

                        }

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.3902439024390244;
                        return;

                        }

                        }

                        }

                }
            
        
            
                /**
                 * Random forest's tree #3
                 */
                void tree3(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[18] < 0.5) {
                            
                        if (x[10] < 0.5) {
                            
                        if (x[0] < 0.5) {
                            
                        if (x[9] < 0.5) {
                            
                        *classIdx = 1;
                        *classScore = 0.2682926829268293;
                        return;

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.34146341463414637;
                        return;

                        }

                        }
                        else {
                            
                        if (x[12] < 0.5) {
                            
                        if (x[7] < 0.5) {
                            
                        *classIdx = 2;
                        *classScore = 0.3902439024390244;
                        return;

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.34146341463414637;
                        return;

                        }

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.34146341463414637;
                        return;

                        }

                        }

                        }
                        else {
                            
                        *classIdx = 2;
                        *classScore = 0.3902439024390244;
                        return;

                        }

                        }
                        else {
                            
                        if (x[22] < 0.5) {
                            
                        if (x[16] < 0.5) {
                            
                        if (x[9] < 0.5) {
                            
                        *classIdx = 2;
                        *classScore = 0.3902439024390244;
                        return;

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.34146341463414637;
                        return;

                        }

                        }
                        else {
                            
                        *classIdx = 2;
                        *classScore = 0.3902439024390244;
                        return;

                        }

                        }
                        else {
                            
                        if (x[9] < 0.5) {
                            
                        if (x[4] < 0.5) {
                            
                        *classIdx = 0;
                        *classScore = 0.34146341463414637;
                        return;

                        }
                        else {
                            
                        *classIdx = 2;
                        *classScore = 0.3902439024390244;
                        return;

                        }

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.34146341463414637;
                        return;

                        }

                        }

                        }

                }
            
        
            
                /**
                 * Random forest's tree #4
                 */
                void tree4(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[26] < 0.5) {
                            
                        if (x[25] < 0.5) {
                            
                        if (x[17] < 0.5) {
                            
                        *classIdx = 1;
                        *classScore = 0.14634146341463414;
                        return;

                        }
                        else {
                            
                        *classIdx = 2;
                        *classScore = 0.1951219512195122;
                        return;

                        }

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.6585365853658537;
                        return;

                        }

                        }
                        else {
                            
                        if (x[12] < 0.5) {
                            
                        if (x[14] < 0.5) {
                            
                        if (x[15] < 0.5) {
                            
                        if (x[23] < 0.5) {
                            
                        *classIdx = 2;
                        *classScore = 0.1951219512195122;
                        return;

                        }
                        else {
                            
                        if (x[19] < 0.5) {
                            
                        *classIdx = 0;
                        *classScore = 0.6585365853658537;
                        return;

                        }
                        else {
                            
                        *classIdx = 2;
                        *classScore = 0.1951219512195122;
                        return;

                        }

                        }

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.6585365853658537;
                        return;

                        }

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.6585365853658537;
                        return;

                        }

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.6585365853658537;
                        return;

                        }

                        }

                }
            
        
            
                /**
                 * Random forest's tree #5
                 */
                void tree5(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[25] < 0.5) {
                            
                        if (x[5] < 0.5) {
                            
                        if (x[13] < 0.5) {
                            
                        *classIdx = 1;
                        *classScore = 0.1951219512195122;
                        return;

                        }
                        else {
                            
                        if (x[27] < 0.5) {
                            
                        if (x[15] < 0.5) {
                            
                        *classIdx = 0;
                        *classScore = 0.4146341463414634;
                        return;

                        }
                        else {
                            
                        *classIdx = 2;
                        *classScore = 0.3902439024390244;
                        return;

                        }

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.4146341463414634;
                        return;

                        }

                        }

                        }
                        else {
                            
                        if (x[18] < 0.5) {
                            
                        *classIdx = 0;
                        *classScore = 0.4146341463414634;
                        return;

                        }
                        else {
                            
                        *classIdx = 2;
                        *classScore = 0.3902439024390244;
                        return;

                        }

                        }

                        }
                        else {
                            
                        if (x[15] < 0.5) {
                            
                        if (x[23] < 0.5) {
                            
                        if (x[16] < 0.5) {
                            
                        *classIdx = 2;
                        *classScore = 0.3902439024390244;
                        return;

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.4146341463414634;
                        return;

                        }

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.4146341463414634;
                        return;

                        }

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.4146341463414634;
                        return;

                        }

                        }

                }
            
        
            
                /**
                 * Random forest's tree #6
                 */
                void tree6(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[3] < 0.5) {
                            
                        if (x[29] < 0.5) {
                            
                        if (x[23] < 0.5) {
                            
                        if (x[13] < 0.5) {
                            
                        *classIdx = 1;
                        *classScore = 0.1951219512195122;
                        return;

                        }
                        else {
                            
                        if (x[26] < 0.5) {
                            
                        *classIdx = 2;
                        *classScore = 0.4146341463414634;
                        return;

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.3902439024390244;
                        return;

                        }

                        }

                        }
                        else {
                            
                        if (x[17] < 0.5) {
                            
                        *classIdx = 2;
                        *classScore = 0.4146341463414634;
                        return;

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.3902439024390244;
                        return;

                        }

                        }

                        }
                        else {
                            
                        if (x[22] < 0.5) {
                            
                        *classIdx = 2;
                        *classScore = 0.4146341463414634;
                        return;

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.3902439024390244;
                        return;

                        }

                        }

                        }
                        else {
                            
                        if (x[25] < 0.5) {
                            
                        if (x[19] < 0.5) {
                            
                        *classIdx = 0;
                        *classScore = 0.3902439024390244;
                        return;

                        }
                        else {
                            
                        *classIdx = 2;
                        *classScore = 0.4146341463414634;
                        return;

                        }

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.3902439024390244;
                        return;

                        }

                        }

                }
            
        
            
                /**
                 * Random forest's tree #7
                 */
                void tree7(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[26] < 0.5) {
                            
                        if (x[17] < 0.5) {
                            
                        if (x[1] < 0.5) {
                            
                        if (x[21] < 0.5) {
                            
                        *classIdx = 1;
                        *classScore = 0.21951219512195122;
                        return;

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.4634146341463415;
                        return;

                        }

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.4634146341463415;
                        return;

                        }

                        }
                        else {
                            
                        *classIdx = 2;
                        *classScore = 0.3170731707317073;
                        return;

                        }

                        }
                        else {
                            
                        if (x[27] < 0.5) {
                            
                        *classIdx = 0;
                        *classScore = 0.4634146341463415;
                        return;

                        }
                        else {
                            
                        if (x[0] < 0.5) {
                            
                        if (x[13] < 0.5) {
                            
                        *classIdx = 0;
                        *classScore = 0.4634146341463415;
                        return;

                        }
                        else {
                            
                        *classIdx = 2;
                        *classScore = 0.3170731707317073;
                        return;

                        }

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.4634146341463415;
                        return;

                        }

                        }

                        }

                }
            
        
            
                /**
                 * Random forest's tree #8
                 */
                void tree8(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[7] < 0.5) {
                            
                        if (x[11] < 0.5) {
                            
                        if (x[5] < 0.5) {
                            
                        *classIdx = 1;
                        *classScore = 0.07317073170731707;
                        return;

                        }
                        else {
                            
                        *classIdx = 2;
                        *classScore = 0.3170731707317073;
                        return;

                        }

                        }
                        else {
                            
                        if (x[3] < 0.5) {
                            
                        if (x[8] < 0.5) {
                            
                        *classIdx = 2;
                        *classScore = 0.3170731707317073;
                        return;

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.6097560975609756;
                        return;

                        }

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.6097560975609756;
                        return;

                        }

                        }

                        }
                        else {
                            
                        if (x[14] < 0.5) {
                            
                        if (x[8] < 0.5) {
                            
                        *classIdx = 0;
                        *classScore = 0.6097560975609756;
                        return;

                        }
                        else {
                            
                        *classIdx = 2;
                        *classScore = 0.3170731707317073;
                        return;

                        }

                        }
                        else {
                            
                        if (x[5] < 0.5) {
                            
                        *classIdx = 2;
                        *classScore = 0.3170731707317073;
                        return;

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.6097560975609756;
                        return;

                        }

                        }

                        }

                }
            
        
            
                /**
                 * Random forest's tree #9
                 */
                void tree9(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[9] < 0.5) {
                            
                        if (x[21] < 0.5) {
                            
                        if (x[18] < 0.5) {
                            
                        if (x[19] < 0.5) {
                            
                        *classIdx = 1;
                        *classScore = 0.24390243902439024;
                        return;

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.43902439024390244;
                        return;

                        }

                        }
                        else {
                            
                        if (x[13] < 0.5) {
                            
                        *classIdx = 2;
                        *classScore = 0.3170731707317073;
                        return;

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.43902439024390244;
                        return;

                        }

                        }

                        }
                        else {
                            
                        *classIdx = 2;
                        *classScore = 0.3170731707317073;
                        return;

                        }

                        }
                        else {
                            
                        if (x[18] < 0.5) {
                            
                        if (x[29] < 0.5) {
                            
                        if (x[0] < 0.5) {
                            
                        *classIdx = 2;
                        *classScore = 0.3170731707317073;
                        return;

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.43902439024390244;
                        return;

                        }

                        }
                        else {
                            
                        *classIdx = 2;
                        *classScore = 0.3170731707317073;
                        return;

                        }

                        }
                        else {
                            
                        *classIdx = 0;
                        *classScore = 0.43902439024390244;
                        return;

                        }

                        }

                }
            
        

            
};




#endif